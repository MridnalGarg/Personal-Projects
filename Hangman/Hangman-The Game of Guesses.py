import random


def get_guess(guessed):
    while True:
        guess = input("Your Guess: ")
        guess = guess.lower()
        if len(guess) != 1:
            print("Oop! your guess might have a problem...")
        elif guess in guessed:
            print("You have already guessed that letter.")
        elif guess not in 'abcdefghijklmnopqrstuvwxyz':
            print("Oops! your guess is not a letter.")
        else:
            return guess


def play_again():
    print("\nWant to play again? (y/n): ")
    x = input().lower()
    if x == 'y':
        return True
    elif x == 'n':
        print("\nHope we see you again :) ")
        exit(0)
    else:
        print("\nOops! Wrong option...")
        return play_again()



def game_display(wrong_guesses, correct_guesses, word):
    HANGMAN = ['''
                                          +---+
                                          |   |
                                          0   |
                                              |
                                              |
                                              |
                                       =========''', '''
                                          +---+
                                          |   |
                                          0   |
                                          |   |
                                              |
                                              |
                                        =========''', '''
                                          +---+
                                          |   |
                                          0   |
                                         /|   |
                                              |
                                              |
                                        =========''', '''
                                          +---+
                                          |   |
                                          0   |
                                         /|\  |
                                              |
                                              |
                                        =========''', '''
                                          +---+
                                          |   |
                                          0   |
                                         /|\  |
                                         /    |
                                              |
                                        =========''', '''
                                          +---+
                                          |   |
                                          0   |
                                         /|\  |
                                         / \  |
                                              |
                                        =========''']

    print("***********************************************************************************")
    print(HANGMAN[len(wrong_guesses)])
    print("\nWord Guess: ", end=' ')

    # replace unguessed letter by ' _ '
    for i in range(len(word)):
        if word[i] in correct_guesses:
            print(word[i], end=' ')
        else:
            print('_', end=' ')


print("""
***********************************************************************************
			         HANGMAN
***********************************************************************************
""")

player_name = input("Enter player name: ")
print("Welcome " + player_name + """!  
We got a situation here for you. A man has been hanged up by the rope and he need your
help to get out. You need to guess the secret code which is a secret WORD. 

Rules:
           1.  You will get 5 chances, everytime you guess a wrong letter 1 chance will be
	deducted and the man moves 1 step forward towards death.
           2. Guess the word letter by letter.
           3. You got time, so don't be in a hurry.
We wish you LUCK!

""")

#reads the file "randomwords.txt" word by word
words = open("randomwords.txt").read().split()

# Select a random word from this list of words
word = random.choice(words)

wrong_guesses = ''
correct_guesses = ''
chances = 5
gameover = False

while True:
    print()
    game_display(wrong_guesses, correct_guesses, word)
    print()
    print("Chances left: ", chances)
    guess = get_guess(wrong_guesses + correct_guesses)
    if guess in word:
        correct_guesses = correct_guesses + guess

        # check if the player already won
        win = True
        for i in range(len(word)):
            if word[i] not in correct_guesses:
                win = False
                break
        if win:
            print("\nYes! The word is " + word + "!\nCONGRATULATIONS!!! You have won!")
            gameover = True
    else:
        wrong_guesses = wrong_guesses + guess
        chances -= 1
        # check number of chances left
        if chances == 0:
            game_display(wrong_guesses, correct_guesses, word)
            print("\n\nOops! you lost...\nYou have run out of guesses!\nThe word was \"" + word + " \" ")
            gameover = True
    if gameover:
        if play_again():
            wrong_guesses = ''
            correct_guesses = ''
            chances = 5
            gameover = False
            word = random.choice(words)
        else:
            break
