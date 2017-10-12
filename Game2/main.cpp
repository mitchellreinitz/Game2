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
        if (location == "start")
        {
            cout << "You are in the middle of a forest. \n You see a trail to your north. The trail runs east to west. \n";
            cin >> choice;
            if (choice == "north")
            {
                cout << "You have reached the trail.";
                location = "trail";
            }
            else if (choice == "south")
            {
                cout << "You headed south. You encounter a cliff. \n";
                location = "southcliff";
                cin >> choice;
                if (choice == "north")
                {
                    location = "start";
                }
            }
            else if (choice == "west")
            {
                cout << "You headed west. You encounter a cliff. \n";
                location = "westcliff";
                cin >> choice;
                if (choice == "east")
                {
                    location = "start";
                }
            }
            else if (choice == "east")
            {
                cout << "You headed east. You encounter a cliff. \n";
                location = "eastcliff";
                cin >> choice;
                if (choice == "west")
                {
                    location = "start";
                }
            }
            else if (choice != "q" || choice != "Q")
            {
                cout << "That is irrelevant.\n";
            }
        }
        else if (location == "trail")
            {
            cout << "You are at the beginning of the trail. You may either go east or west. \n";
            cin >> choice;
            }
            if (choice == "east")
            {
                location = "trailblazer 41";
                cout << "You headed east. You are at trailblazer 41. \n";
                
                if (choice == "east")
                {
                    cout << "You come to a fork in the trail. Would you like to go left or right? \n";
                    location = "trailblazer 41";
                    cin >> choice;
                    if (choice == "right")
                    {
                        cout << "You have gone right and you're located at Trailblazer 40A. There is a tree in your way. \n";
                        location = "trailblazer 40A";
                        cin >> choice;
                        if (choice == "west")
                        {
                            cout << "You are at trailblazer 42. \n";
                            location = "trailblazer 42";
                        }
               
                    }
                    else if (choice == "left")
                    {
                        cout << "You have reached trailblazer 40B. You see smoke in the distance. \n";
                        cin >> choice;
                        if (choice == "east")
                        {
                            cout << "You are now in a large field. There is a gallon of gasoline in the large field. However, the surrounding area is on fire. Picking up the gasoline would be risky.\n";
                            location = "field";
                            cin >> choice;
                            if(choice == "grab")
                            {
                                cout << "You have picked up gasoline. \n";
                                cin >> choice;
                                if (choice == "west")
                                {
                                    cout << "You went west and are at trailblazer 40B. \n";
                                    location = "trailblazer 40B";
                                    cin >> choice;
                                }
                            }
                        }
                    }
                }
            }
                if (choice == "west")
                {
                    cout << "You see a man. He has a map. He offers it to you. \n";
                    cin >> choice;
                    if (choice == "grab")
                    {
                        cout << "You now have a map.\n";
                        cin >> choice;
                        if (choice == "east")
                        {
                            location = "trailblazer 41";
                        }
                    }
                }
            else if (choice != "q" && choice != "Q")
            {
                cout << "That is irrelevant.\n";
            }
        }
        if (location == "trailblazer 40B")
        {
            if (choice == "west")
            {
                location = "trailblazer 41";
            }
            if (choice == "east")
            {
                location = "field";
            }
        }
        else if (location == "trailblazer 41")
        {
            cin >> choice;
            if (choice == "west")
            {
                location = "trail";
            }
        }
        else if (location == "field")
        {
            cin >> choice;
            if (choice == "west")
            {
                location = "trailblazer 40B";
            }
        }
    return 0;
}
