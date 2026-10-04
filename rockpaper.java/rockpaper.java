
import java.util.Scanner;

public class rockpaper {
    public static void main(stirng args[]){
        Scanner scanner = new Scanner (System.in);
       
        int wins =0;
        int losses =0;
        int draws =0;
        int rounds =0;
        String[] compputerMoves = {"rock","paper","scissor"};
        String[] 
    }
         String[] playermoves = new String[rounds]; 
         String[] computermove = newString[rounds];
        for (int i=0; i<rounds;i++){
            while(true){
            System.out.print("round" + (i+1) + " enter your move");
            playermoves[i] = scanner.next();
            if (playermoves[i].equalsIgnoreCase(anotherString:"rock")) ||
            playermoves[i].equalsIgnoreCase(anotherString:"paper") ||
            playermoves[i].equalsIgnoreCase(anotherString:"scissors")
            {
                break;
            } else {
                System.out.println("Invalid move. Please enter rock, paper, or scissors.");

            } computerMove[i] = move[random.nestInt(bound: 3)];
            results[i]= playRound(playerMove[i],computerMove[i]);
            private static String playRound(String playerMove, String computerMove){
                if (playerMove.equalsIgnoreCase(computerMove)){
                    return "draw";
                } else if ((playerMove.equalsIgnoreCase("rock") && computerMove.equalsIgnoreCase("scissors")) ||
                (playerMove.equalsIgnoreCase("paper") && computerMove.equalsIgnoreCase("rock")) ||
                (playerMove.equalsIgnoreCase("scissors") && computerMove.equalsIgnoreCase("paper"))){
                    return "win";
                } else {
                    return "lose";
                }

    
            }



        }    

        
        
    