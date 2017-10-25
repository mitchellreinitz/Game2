//
//  main.cpp
//  Game2
//
//  Created by Mitchell Reinitz on 10/2/17.
//  Copyright © 2017 Mitchell Reinitz. All rights reserved.
//
#include <iostream>
#include <string>

using namespace std;
int main() // the code was generally cleaned up after suggestions from the code review
{
    string location = "start";
    string choice = "";
    int map = 0;
    int gas = 0;
    int health = 3;
    int saw = 0;
    while (choice != "q" && choice != "Q")
    {
       
        if (location == "start") // beginning starting position
        {
            cout << "You are in the middle of a forest. You see a trail to the north. The trail runs east to west. You want to go home. \n";
            cout << ">";
            cin >> choice;
            if (choice == "north") // if player chooses this, they go to the beginning of the trail (trail)
            {
                location = "trail";
            }
            else if (choice == "south") // player went south at the start of the game (southcliff)
            {
                location = "southcliff";
            }
            else if (choice == "west") // player went west at the start of the game (westcliff)
            {
                location = "westcliff";
            }
            else if (choice == "east") // player went east at the start of the game (eastcliff)
            {
                location = "eastcliff";
            }
            else if (choice != "q" || choice != "Q")
            {
                cout << "That is irrelevant. \n";
            }
        }
        
        
        
        
        else if (location == "southcliff") // here, they find a saw which they will need to cut apart the tree on 40A
        {
            saw = 1;
            cout << "You headed south. You found and picked up a saw. \n";
            cout << ">";
            cin >> choice;
            if (choice == "north")
            {
                location = "start";
            }
            else if (choice == "south")
            {
                health = 0; // they fell off the cliff
            }
            else if (choice != "q" || choice != "Q")
            {
                cout << "That is irrelevant. \n";
            }
        }
        
        
        
        
        
        else if (location == "eastcliff") // here, they are sent back to the start of the game
        {
            cout << "You headed east. You encounter a cliff. \n";
            cout << ">";
            cin >> choice;
            if (choice == "west")
            {
                location = "start";
            }
            else if (choice == "east")
            {
                health = 0; // they fell off the cliff
            }
            else if (choice != "q" || choice != "Q")
            {
                cout << "That is irrelevant. \n";
            }
        }
        
        
        
        
        else if (location == "westcliff") // here, they are sent back to the start of the game
        {
            cout << "You headed west. You encounter a cliff. \n";
            cout << ">";
            cin >> choice;
            if (choice == "east")
            {
                location = "start";
            }
            else if (choice == "west")
            {
                health = 0; // they fell off the cliff
            }
            else if (choice != "q" || choice != "Q")
            {
                cout << "That is irrelevant. \n";
            }
        }
        
        
        
        
        else if (location == "trail") // they are at the beginning of the trail. if they go west, they should be at trailblazer 42 and if they go east they should be at trailblazer 41. 41 should fork into A and B.
        {
            cout << "You are at the beginning of the trail. \n";
            cout << ">";
            cin >> choice;
            if (choice == "east")
            {
                location = "trailblazer41";
            }
            else if (choice == "west")
            {
                location = "trailblazer42";
            }
            else if (choice == "south")
            {
                location = "start";
            }
            else if (choice == "north")
            {
                cout << "Watch your step. \n";
                health = 0;
            }
            else if (choice != "q" || choice != "Q")
            {
                cout << "That is irrelevant. \n";
            }
        }
        
             
                
                
        else if (location == "trailblazer40B") // if the player went left at the fork, they come here
        {
            cout << "You are at Trailblazer 40B. \n";
            cout << ">";
            cin >> choice;
            if (choice == "west")
            {
                location = "trailblazer41";
            }
            else if (choice == "east")
            {
                location = "field";
            }
            else if (choice != "q" || choice != "Q")
            {
                cout << "That is irrelevant. \n";
            }
        }
        
                
        
                
        else if (location == "trailblazer40A") // if they go right at the fork, they will end up here
        {
            cout << "You are at Trailblazer 40A \n";
            cout << ">";
            cin >> choice;
            if (choice == "east")
            {
                location = "blockedtrail";
            }
            else if (choice == "west")
            {
                location = "trailblazer41";
            }
            else if (choice != "q" || choice != "Q")
            {
                cout << "That is irrelevant. \n";
            }
        }
                
            
                
             
        else if (location == "blockedtrail") // They cannot pass here unless they have a saw. They need to noget a map to find an alternate route
        {
            if (saw == 0)
            {
                cout << "You have come across a tree in your way. As of now, you do not know of a way to get around it. Where would you like to go? \n";
                cout << ">";
                cin >> choice;
                if (choice == "west")
                {
                    location = "trailblazer40A";
                }
            }
            else if (saw == 1)
            {
                location = "parkinglot";
            }
            else if (choice != "q" || choice != "Q")
            {
                cout << "That is irrelevant. \n";
            }
        }
           
        
        
        else if (location == "parkinglot") // Once they find the saw, they will be able to cut apart the debris at blockedtrail and arrive here
        {
            cout << "You cut the tree out of your way and you see a car! Would you like to investigate it? \n";
            cout << ">";
            cin >> choice;
            if (choice == "yes")
            {
                location = "car";
            }
            else if (choice == "no")
            {
                cout << "Would you like to go west?";
                if (choice == "yes")
                {
                    location = "blockedtrail";
                }
                else if (choice == "no")
                {
                    location = "parkinglot";
                }
            }
            else if (choice != "q" || choice != "Q")
            {
                cout << "That is irrelevant. \n";
            }
        }
        
                
        else if (location == "trailblazer42") // if the player goes west from the start of the trail, they come here and they should pick up a map here
        {
            cout << "You are at Trailblazer 42. You see a man here. You may approach him. \n";
            cout << ">";
            cin >> choice;
            if (choice == "approach")
            {
                map = 1;
                cout << "You now have a map. After reading it, you realize that there is a parking lot past Trailblazer 40A. It also indicates that there is a saw somewhere that looks familiar. \n";
                cout << ">";
                cin >> choice;
                if (choice == "east")
                {
                    location = "trail";
                }
                else if (choice == "west")
                {
                    cout << "Now you know where the bears live. \n";
                    health = 0;
                }
            }
            else if (choice != "q" || choice != "Q")
            {
                cout << "That is irrelevant. \n";
            }
        }
                
                
                
                
        else if (location == "trailblazer41") // if they go east at the start of the trail or west at either 40B or 40A, they will end up here
        {
            cout << "You are at Trailblazer 41. \n";
            cout << ">";
            cin >> choice;
            if (choice == "west")
            {
                location = "trail";
            }
            else if (choice == "east")
            {
                location = "fork";
            }
            else if (choice != "q" || choice != "Q")
            {
                cout << "That is irrelevant. \n";
            }
        }
         
           
                
                
        else if (location == "fork") // here, they can go left (40B) or right (40A)
        {
            cout << "You have come to a fork in the trail. You may either go left or right. \n";
            cout << ">";
            cin >> choice;
            if (choice == "right")
            {
                location = "trailblazer40A";
            }
            else if (choice == "left")
            {
                location = "trailblazer40B";
            }
            else if (choice != "q" || choice != "Q")
            {
                cout << "That is irrelevant. \n";
            }
        }
        
        
        
        
        else if (location == "field") // If the player went east at trailblazer 40B, they come here to get the gasoline.
        {
            cout << "You encounter a large field. It is on fire but you see a container of gasoline. You may grab it if you would like. \n";
            cout << ">";
            cin >> choice;
            if (choice == "grab")
            {
                gas = 1;
                cout << "You grabbed the gasoline. The fire is closing in on you on all sides except for the west. Where would you like to go? \n";
                cout << ">";
                cin >> choice;
                    if (choice == "west")
                    {
                        location = "trailblazer40B";
                    }
                    else if (choice != "west")
                    {
                        health = 0;
                    }
            }
            else if (choice == "west")
            {
                location = "trailblazer40B";
            }
            else if (choice != "q" || choice != "Q")
            {
                cout << "That is irrelevant. \n";
            }
        }
    

        
        else if (location == "car")
        {
            cout << "Would you like to try and start the car? \n";
            cout << ">";
            cin >> choice;
            if (choice == "yes" && gas == 0)
            {
                cout << "Unless you have gas for the car, you cannot start it. \n";
            }
            else if (choice == "yes" && gas == 1)
            {
                cout << "\n \n Congratulations! You have started the car and are free to go home. You have made it out of the forest without dying. \n";
                return 0;
            }
        }
        
        
        if (health == 0) // when the player reaches 0 health, they die
        {
            cout << "Be careful. You were killed due to your actions. \n";
            return 0;
        }
        
        
        
        
    
        
        }
    return 0;
}
