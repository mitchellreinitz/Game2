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
int main()
{
    string location = "start";
    string choice = "";
    while (choice != "q" && choice != "Q")
    {
        
        
        
        if (location == "start") // beginning starting position
        {
            cout << "You are in the middle of a forest. \n You see a trail to your north. The trail runs east to west. \n";
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
        
        
        
        
        else if (location == "southcliff") // here, they are sent back to the start of the game
        {
            cout << "You headed south. You encounter a cliff. \n";
            cout << ">";
            cin >> choice;
            if (choice == "north")
            {
                location = "start";
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
            else if (choice != "q" || choice != "Q")
            {
                cout << "That is irrelevant. \n";
            }
        }
        
        
        
        
        else if (location == "trail") // they are at the beginning of the trail. if they go west, they should be at trailblazer 42 and if they go east they should be at trailblazer 41. 41 should fork into A and B.
        {
            cout << "You are at the beginning of the trail. You may either go east or west. \n";
            cin >> choice;
            if (choice == "east")
            {
                location = "trailblazer41";
            }
            else if (choice == "west")
            {
                location = "trailblazer42";
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
                
            
                
             
        else if (location == "blockedtrail") // They cannot pass here. They need get a map to find an alternate route
        {
            cout << "You have come across a tree in your way. As of now, you do not know of a way to get around it. Where would you like to go? \n";
            cout << ">";
            cin >> choice;
            if (choice == "west")
            {
                location = "trailblazer40A";
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
                cout << "The man gave you a map. He left. \n";
                cout << ">";
                cin >> choice;
                if (choice == "east")
                {
                    location = "trail";
                }
            }
            else if (choice == "east")
            {
                location = "trail";
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
                cout << "You grabbed the gasoline. The fire is closing in on you on all sides except for the west. Where would you like to go? \n";
                cout << ">";
                cin >> choice;
                    if (choice == "west")
                    {
                        location = "trailblazer40B";
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
    
         
                
                
        }
    return 0;
}
