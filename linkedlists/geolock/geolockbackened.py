import random
import networkx as nx
GRID_SIZE = 10
def zone_of(r, c):
    half = GRID_SIZE // 2
    if r < half and c < half:
        return "NW"
    if r < half and c >= half:
        return "NE"
    if r >= half and c < half:
        return "SW"
    return "SE"
def assign_cell():
    r = random.randint(0, GRID_SIZE - 1)
    c = random.randint(0, GRID_SIZE - 1)
    return {"r": r, "c": c, "key": f"R{r}C{c}", "zone": zone_of(r, c)}
class Wallet:
    def __init__(self, wallet_id, name, balance):
        self.id = wallet_id
        self.name = name
        self.balance = balance
        self.cell = assign_cell()
        self.zone = self.cell["zone"]
        self.status = "normal"
        self.frozen_since = None
    def __repr__(self):
        return f"<Wallet {self.id} {self.name} zone={self.zone} status={self.status}>"
class Ledger:
    def __init__(self):
        self.wallets = {}
        self.transactions = []
        self.clock = 0
        self._wallet_count = 0
    def register_wallet(self, name, balance=10000):
        self._wallet_count += 1
        wallet_id = f"W{self._wallet_count:02d}"
        self.wallets[wallet_id] = Wallet(wallet_id, name, balance)
        return wallet_id
    def send(self, from_id, to_id, amount):
        fw, tw = self.wallets[from_id], self.wallets[to_id]
        if fw.status == "frozen":
            raise ValueError(f"{fw.name}'s wallet is frozen — transfer blocked.")
        if amount <= 0 or fw.balance < amount:
            raise ValueError("Invalid amount or insufficient balance.")
        self.clock += 1
        fw.balance -= amount
        tw.balance += amount
        tx = {"id": f"TX{self.clock}", "from": from_id, "to": to_id,
              "amount": amount, "t": self.clock, "zone": tw.zone}
        self.transactions.append(tx)
        return tx
    def as_graph(self):
        g = nx.MultiDiGraph()
        for w in self.wallets.values():
            g.add_node(w.id, name=w.name, zone=w.zone, status=w.status)
        for tx in self.transactions:
            g.add_edge(tx["from"], tx["to"], amount=tx["amount"], t=tx["t"])
        return g
WEIGHTS = {
    "match_ratio": 0.35,
    "fanout":      0.20,
    "speed":       0.20,
    "hop_depth":   0.15,
    "frequency":   0.10,
}
def compute_risk(total_traced, reported_amount, distinct_destinations,
                  avg_gap, max_hop_reached, tx_count):
    match_ratio = min(100, round((total_traced / reported_amount) * 100)) if reported_amount else 0
    fanout = min(100, distinct_destinations * 22)
    speed = min(100, max(0, 100 - avg_gap * 12))
    hop_depth = min(100, max_hop_reached * 30)
    frequency = min(100, tx_count * 18)
    final = round(
        match_ratio * WEIGHTS["match_ratio"] +
        fanout * WEIGHTS["fanout"] +
        speed * WEIGHTS["speed"] +
        hop_depth * WEIGHTS["hop_depth"] +
        frequency * WEIGHTS["frequency"]
    )
    return {
        "match_ratio": match_ratio,
        "fanout": fanout,
        "speed": speed,
        "hop_depth": hop_depth,
        "frequency": frequency,
        "final": final,
        "label": "High" if final >= 70 else "Moderate" if final >= 40 else "Low",
    }
def report_scam(ledger, victim_id, suspect_id, amount, max_hops=2):
    victim = ledger.wallets[victim_id]
    suspect = ledger.wallets[suspect_id]
    log = []
    log.append(f"{victim.name} reported a scam involving {suspect.name} — Rs.{amount} lost.")
    incoming = [tx for tx in ledger.transactions
                if tx["from"] == victim_id and tx["to"] == suspect_id]
    since_t = min((tx["t"] for tx in incoming), default=ledger.clock)
    suspect.status = "frozen"
    suspect.frozen_since = ledger.clock
    log.append(f"FREEZE: {suspect.name} ({suspect.id}) frozen instantly. "
               f"Zone {suspect.zone}, cell {suspect.cell['key']} flagged for investigation.")
    graph = ledger.as_graph()
    visited = {suspect_id}
    destinations = set()
    total_traced = 0
    tx_count = 0
    gap_sum = 0
    gap_count = 0
    max_hop_reached = 0
    def trace(wallet_id, since, hop):
        nonlocal total_traced, tx_count, gap_sum, gap_count, max_hop_reached
        if hop > max_hops:
            return
        max_hop_reached = max(max_hop_reached, hop)
        outgoing = [tx for tx in ledger.transactions
                    if tx["from"] == wallet_id and tx["t"] >= since]
        if not outgoing:
            return
        hop_sum = sum(tx["amount"] for tx in outgoing)
        total_traced += hop_sum
        for tx in outgoing:
            tx_count += 1
            gap_sum += (tx["t"] - since)
            gap_count += 1
            if tx["to"] in visited:
                continue
            visited.add(tx["to"])
            destinations.add(tx["to"])
            dest = ledger.wallets[tx["to"]]
            close_match = abs(hop_sum - amount) <= amount * 0.25
            dest.status = "frozen" if close_match else "watch"
            tag = "CASCADE FREEZE" if close_match else "WATCH"
            log.append(f"{tag} (hop {hop}): Rs.{tx['amount']} moved to {dest.name} "
                       f"({dest.id}) in zone {dest.zone}.")
            trace(tx["to"], tx["t"], hop + 1)
    trace(suspect_id, since_t, 1)
    avg_gap = gap_sum / gap_count if gap_count else 0
    scores = compute_risk(total_traced, amount, len(destinations),
                           avg_gap, max_hop_reached, tx_count)
    log.append(f"Trace complete. Rs.{total_traced} tracked across "
               f"{len(destinations)} wallet(s), max depth {max_hop_reached} hop(s).")
    log.append(f"Composite risk score: {scores['final']} / 100 ({scores['label']}).")
    undirected = graph.to_undirected()
    clusters = list(nx.connected_components(undirected))
    centrality = nx.betweenness_centrality(graph)
    return {
        "log": log,
        "scores": scores,
        "total_traced": total_traced,
        "destinations": destinations,
        "clusters": clusters,
        "centrality": centrality,
    }
def investigation_report(ledger, victim_id, suspect_id, amount, result):
    victim = ledger.wallets[victim_id]
    suspect = ledger.wallets[suspect_id]
    scores = result["scores"]
    lines = [
        "INVESTIGATION SUMMARY",
        f"Reported by: {victim.name} ({victim.id}, zone {victim.zone})",
        f"Suspect wallet: {suspect.name} ({suspect.id}), "
        f"cell {suspect.cell['key']}, zone {suspect.zone}",
        f"Reported loss: Rs.{amount}   |   Traced outflow: Rs.{result['total_traced']}",
        f"Destinations implicated: {len(result['destinations'])}",
        f"Risk score: {scores['final']} / 100 ({scores['label']})",
        "",
        "This score and the linked wallets are an investigative lead, not proof "
        "of fraud. All conclusions remain traceable to the underlying transaction log.",
    ]
    return "\n".join(lines)
if __name__ == "__main__":
    random.seed(7)
    ledger = Ledger()
    priya = ledger.register_wallet("Priya", 15000)
    suspect_b = ledger.register_wallet("Suspect_B", 500)
    mule1 = ledger.register_wallet("Mule_1", 200)
    mule2 = ledger.register_wallet("Mule_2", 200)
    mule3 = ledger.register_wallet("Mule_3", 200)
    ledger.send(priya, suspect_b, 6000)
    ledger.send(suspect_b, mule1, 2200)
    ledger.send(suspect_b, mule2, 1900)
    ledger.send(suspect_b, mule3, 1800)
    result = report_scam(ledger, priya, suspect_b, amount=6000, max_hops=2)
    print("\n".join(result["log"]))
    print()
    print(investigation_report(ledger, priya, suspect_b, 6000, result))