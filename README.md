leaatPowerfulChessGame
======================

A (a lot needed to be improved) chess game based on Qt.
This is for my Programming In Computing course's final project. We are using Qt to create a game based on our own design. 

Here's some brief introduction about the game.

The pieces are not programmed in the way of OO. They are just QLabels with strings on them. By moving the pieces I am actually moving the strings. The cursor is also not so well-functioned. I use the paintevent and repaint to "mimic" a cursor by differing the paint color of the previous coordinates of cursor with the next movement. By doing this I am unable to implement some real cursor function like highlighting the selection and keeping the pieces' color.

Using Qt to program a game is not as I expected in the beginning. What I imagined was some Adobe Flash like stuff. We "draw" the objects and adding ActionScript to them, which is pretty much like OOP in an intuitive way. Maybe I just havent get the idea of Qt but to be honest I did not enjoy programing game with Qt that much.

Press X to select the piece. Press C to cancel. Press X again to drop the piece. There is no movement restriction nor winning detection window. The rules are by players themselves.

Well the good thing is by this chess "engine" we can quickly reimplement some other kind of chess game(still, no movement restrction and also poor graphics) like Chinese chess, Shogi, Go or some others that you may invent by yourself. Just relocate the pieces and change the names and board size, probably some tiny change to the cursor function. All of which can be done in five minutes.
