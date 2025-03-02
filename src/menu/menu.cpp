#include "menu.h"
#include <iostream>

void startMenu()
{    
    int actions;
    std::cout <<"\033c";
    std:: cout <<"~+~-~+~-~+~-~+~-~+~-~+~-~"<<std::endl<< "     Forest Friends" <<std::endl<<"~+~-~+~-~+~-~+~-~+~-~+~-~"<<std::endl<<std::endl;
    std:: cout << "HeLLo! And Welcome to FF!"<<std::endl<<"Would you start to play?"<<std::endl<<std::endl;
    std::cout << "~-~ 1. Start" << std::endl;
    std::cout << "~-~ 2. Rules" << std::endl;
    std::cout << "~-~ 3. Settings" << std::endl;
    std::cout << "~-~ 4. Exit" << std::endl;
    std::cout << std::endl << "-------------------------"<<std::endl;
    std::cout << "Please, enter the action (1,2,3 or 4): ";
    std::cin >> actions;
    if (actions==1)
    {
        startGame();
    }
        else if (actions==2)
        {
            rulesGame();  
        }
        else if (actions == 3) 
        {
            settings(); 
        }
        else if (actions == 4)
        {
            exitGame();
        }
        else 
        {
            errorMenu();
            startMenu();
    }
};

int exitGame()
{
    std::cout <<"\033c";
    std::cout <<"~+~-~+~-~+~-~+~-~+~-~+~-~"<<std::endl<< "     Forest Friends" <<std::endl<<"~+~-~+~-~+~-~+~-~+~-~+~-~"<<std::endl<<std::endl;
    std::cout << "Goodbye! Thanks for playing FF!"<<std::endl;
    //??????;  
    return 0;
};
void settings()
{
    int actions;
    std::cout <<"\033c";
    std::cout <<"~+~-~+~-~+~-~+~-~+~-~+~-~"<<std::endl<< "     Forest Friends" <<std::endl<<"~+~-~+~-~+~-~+~-~+~-~+~-~"<<std::endl<<std::endl;
    std::cout << "**Some settings**"<<std::endl;
    
    std::cout<<"That's all!"<<std::endl<<"Return to menu?"<<std::endl; 
    std::cout << "~-~ 1. Return to Menu" << std::endl;
    std::cout << "~-~ 2. Exit" << std::endl;
    std::cout << std::endl << "-------------------------"<<std::endl;
    std::cout << "Please, enter the action (1 or 2): ";
    std::cin >> actions;
    if (actions==1)
    {
        startMenu();
    }
    else if (actions==2)
    {
        exitGame();
    }
    else 
    {
        errorMenu();
        settings();

    }
};

void startGame()
{
    std::cout <<"\033c";
    std::cout <<"~+~-~+~-~+~-~+~-~+~-~+~-~"<<std::endl<< "     Forest Friends" <<std::endl<<"~+~-~+~-~+~-~+~-~+~-~+~-~"<<std::endl<<std::endl;
    std::cout << "**Game has been started**"<<std::endl;
};

void rulesGame()
{
    int actions;
    std::cout <<"\033c";
    std::cout <<"~+~-~+~-~+~-~+~-~+~-~+~-~"<<std::endl<< "     Forest Friends" <<std::endl<<"~+~-~+~-~+~-~+~-~+~-~+~-~"<<std::endl<<std::endl;
    std::cout << "You are very poor guy, so you start with a very weak weapon..."
    <<std::endl<<"And if you want to win last final battle..."
    <<std::endl<<"You need to farm some gold and upgrade it."
    <<std::endl<<std::endl<<"-------------------------"
    <<std::endl<<std::endl<<"Be careful! Enemies can kill you!"
    <<std::endl<<"So heal your health near campfire if you have some troubles."
    <<std::endl<<"You can buy armor and item upgrades if there is any seller near you."
    <<std::endl<<"Do you think that you ready start Boss Fight? Then, try your luck!" 
    <<std::endl;

    std::cout << std::endl << "-------------------------"<<std::endl<<std::endl;

    std::cout<<"That's all!"<<std::endl<<"Return to menu?"<<std::endl; 
    std::cout << "~-~ 1. Return to Menu" << std::endl;
    std::cout << "~-~ 2. Exit" << std::endl;
    std::cout << std::endl << "-------------------------"<<std::endl;
    std::cout << "Please, enter the action (1 or 2): ";
    std::cin >> actions;
    if (actions==1)
    {
        startMenu();
    }
    else if (actions==2)
    {
        exitGame();
    }
    else 
    {
        errorMenu();
        rulesGame();

    }
    
};

void errorMenu()
{
    int temp;
    std::cout <<"\033c";
    std:: cout <<"~+~-~+~-~+~-~+~-~+~-~+~-~"<<std::endl<< "     Forest Friends" <<std::endl<<"~+~-~+~-~+~-~+~-~+~-~+~-~"<<std::endl<<std::endl;
    std::cout<<"Something went wrong:("<<std::endl<<"Please, try again"<<std::endl; 
    std::cout << "~-~ 1. Try again" << std::endl;
    std::cout << std::endl << "-------------------------"<<std::endl;
    std::cout << "Enter 1 (or another one number):"<<std::endl;
    std::cin>>temp;
};