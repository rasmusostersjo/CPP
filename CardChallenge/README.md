About the Card Challenge:
=========================
This is a memory challenge that lets the user view each card in a deck once,
then each card must be restated in the correct order.
Currently the Card Challenge supports both English and Swedish, which is set
at compile time. If one whiches to add another language, see instructions in the
LanguageSettings header.

To compile, type 'make'. <br/>
In order to start the card challenge, type 'make play' or './Main'.

##Restating cards (English):
Cards are restated as 'value' 'color' (using the hotkeys below).

Ace: 'a' <br/>
Two: '2'<br/>
Three: '3'<br/>
Four: '4'<br/>
Five: '5'<br/>
Six: '6'<br/>
Seven: '7'<br/>
Eight: '8'<br/>
Nine: '9'<br/>
Ten: '1' (!)<br/>
Jack: 'j'<br/>
Queen: 'q'<br/>
King: 'k'<br/>
Joker: 'j'<br/>

Hearts: 'h'<br/>
Clubs: 'c'<br/>
Spades: 's'<br/>
Diamonds: 'd'<br/>

As an example, Jack of Hearts would be restated as "j h".

##Restating cards (Swedish):
Cards are restated as 'color' 'value' (using the hotkeys below).

Ace: 'e'<br/>
Two: '2'<br/>
Three: '3'<br/>
Four: '4'<br/>
Five: '5'<br/>
Six: '6'<br/>
Seven: '7'<br/>
Eight: '8<br/>
Nine: '9'<br/>
Ten: '1' (!)<br/>
Jack: 'n'<br/>
Queen: 'd'<br/>
King: 'k'<br/>
Joker: 'j'<br/>

Hearts: 'h'<br/>
Clubs: 'r'<br/>
Spades: 's'<br/>
Diamonds: 'k'<br/>

As an example, Ace of Spaces would be restated as "s e".

<br/>
(!): Note that Ten is restated by just the '1', which is fine since ace is
restated by 'a'/'e'.
