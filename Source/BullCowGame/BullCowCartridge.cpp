// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    SetupGame();

    PrintLine(TEXT("The HiddenWord is: %s"), *HiddenWord); // Debug Line
    PrintLine(TEXT("It is %i characters long."), HiddenWord.Len()); // Debug line
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    if(bGameOver)
    {
        ClearScreen();
        SetupGame();
        return;
    }
    ProcessGuess(Input);
    
}

void UBullCowCartridge::SetupGame()
{
    PrintLine(TEXT("Welcome to Bull Cows!"));

    Level = 1;

    // TODO: Get random isogram from list based off of level
    // Initialize isogram TODO: Make equal to random isogram from list.
    HiddenWord = TEXT("cake");
    
    Lives = Level + 3;
    bGameOver = false;
    
    PrintLine(TEXT("Guess the %i letter word."), HiddenWord.Len());
    PrintLine(TEXT("Type in your guess.\nPress enter to continue..."));
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press Enter to play again."));
}

void UBullCowCartridge::ProcessGuess(const FString Guess)
{
    if(Guess == HiddenWord)
    {
        PrintLine(TEXT("Congratulations!"));
        PrintLine(TEXT("You have guessed the correct word."));
        EndGame();

        if(++Level > 5)
        {
            PrintLine("You have won the game!");
            EndGame();
        }

        // If No Initialize lives and word based on new level
    }
    else
        {
        if(HiddenWord.Len() != Guess.Len())
        {
            PrintLine(TEXT("The hidden word is %i characters long, try again."), HiddenWord.Len());
            return;
        }

        // Check if isogram

        PrintLine(TEXT("You have lost a life!"));
        PrintLine(TEXT("You have %i lives remaining."), --Lives);

        if(Lives <= 0)
        {
            PrintLine(TEXT("You lose!"));
            PrintLine(TEXT("The current hidden word was \"%s\"."), *HiddenWord);
            EndGame();
            return;
        }
        // Check bulls and cows, display to the player.
        PrintLine("Please try again.");
        }
}
