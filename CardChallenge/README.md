About the Card Challenge:
=========================
This is a memory challenge that lets the user view each card in a deck once,
then each card must be restated in the correct order.
Currently the Card Challenge supports both English and Swedish, which is set
at compile time. If one whiches to add another language, see instructions in the
LanguageSettings header.

<br/>
To compile, type 'make'. In order to start the card challenge, type 'make play'
or './Main'.

Restating cards (English):
==========================
Cards are restated as <value> <color>, using the hotkeys as below.

<br/>

Ace: 'a'
Two: '2'
Three: '3'
Four: '4'
Five: '5'
Six: '6'
Seven: '7'
Eight: '8'
Nine: '9'
Ten: '1' (!)
Jack: 'j'
Queen: 'q'
King: 'k'
Joker: 'j'

<br/>

Hearts: 'h'
Clubs: 'c'
Spades: 's'
Diamonds: 'd'

<br/>
As an example, Jack of Hearts would be restated as "j h".

Restating cards (Swedish):
==========================
Cards are restated as <color> <value>, using the hotkeys as below.

<br/>

Ace: 'e'
Two: '2'
Three: '3'
Four: '4'
Five: '5'
Six: '6'
Seven: '7'
Eight: '8
Nine: '9'
Ten: '1' (!)
Jack: 'n'
Queen: 'd'
King: 'k'
Joker: 'j'

<br/>

Hearts: 'h'
Clubs: 'r'
Spades: 's'
Diamonds: 'k'

<br/>
As an example, Ace of Spaces would be restated as "s e".

<br/>
(!): Note that Ten is restated by just the '1', which is fine since ace is
restated by 'a'/'e'.
