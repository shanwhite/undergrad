// CS211 LAB 1
// Traitor Simulation Game

import java.util.*;

public class TraitorGame {
    public static void main(String[] args) {
        int simulations = 1000000;   // num of trials for the simulation (Monte Carlo)
        int n = 5;    // num of traitors

        int traitorsWin = 0;
        for (int i=0; i<simulations; i++) {
            if (traitorGame(n)) {
                traitorsWin++;
            }
        }

        double probability = (double) traitorsWin / simulations;
        System.out.println("Probability that the traitors will win: " + probability*100 + "%");
    }

    // simulate the game
    public static boolean traitorGame(int traitors) {
        Random rand = new Random();
        int participants = 22;
        int faithful = participants - traitors;
        int[] players = new int[participants];  // 0 if faithful, 1 if traitor

        // initialise traitors
        for (int i=participants-1; i>=traitors; i--) {
            players[i] = 1; // set traitors at the end of the array
        }

        // game runs until 2 players are left
        while (participants>2) {
            // voting phase to banish someone (traitors and faithful)
            int[] banishVotes = new int[participants];  // int array of votes for each player
            
            // each faithful randomly votes at night
            for (int i = 0; i < faithful; i++) {
                banishVotes[rand.nextInt(participants)]++;
            }
            
            // traitors choose one faithful to vote for
            if (faithful>0) {
                for (int j=0; j < traitors; j++) {
                    int chosenFaithful = rand.nextInt(faithful);    
                    banishVotes[chosenFaithful]++;
                }
            }

            int maxVotes = 0;
            int maxVotesPlayer = 0;
            for (int i = 0; i < participants; i++) {
                // if the person at i has more banish votes than the person who has the max votes
                // sort the array such that the person at i is now maxVotes
                if (banishVotes[i] > maxVotes) {
                    maxVotes = banishVotes[i];
                    maxVotesPlayer = i;
                }
            }
            if (maxVotesPlayer < faithful) {    // if player is faithful
                faithful--; // one faithful gone
            }
            if (maxVotesPlayer >= faithful) {    // if player is a traitor
                traitors--; // one traitor gone
            }
            participants--; // total participants -1

            // murder phase (traitors)
            int murderVotes = rand.nextInt(participants);
            if (murderVotes < faithful) {
                faithful--;
            }
            participants--;
        }

        return !(faithful==2);  // traitors win if both players left at the end of the game aren't faithful
    }
}