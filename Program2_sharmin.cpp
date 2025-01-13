#include <iostream>
#include <string>
#include "location.h"
#include "user.h"

using namespace std;

char map[5][5]={ //char array to display the map
        {'.', '.','.','.','.'},
        {'.','.','.','F', '.'},
        {'.','P', 'P', 'F', 'M'},
        {'.', 'A', 'T', 'F', '.'},
        {'.','.','P', '.','.'},
};
//location descriptions, scan availability, and x and y coordinates
location one("You lie on the outskirts of town. It wouldn't be wise to leave without giving a proper goodbye.", false, 0, 0);
location two("You lie on the outskirts of town. It wouldn't be wise to leave without giving a proper goodbye.", false, 1, 0);
location three("You're near the path. You should follow it if you've been to the abandoned library already.", false, 2, 0);
location four("You're near the abandoned library, you should go check out the town entrance first.", false, 3, 0);
location five("You lie on the outskirts of town. It wouldn't be wise to leave without giving a proper goodbye.", false, 4, 0);
location six("You lie on the outskirts of town. It wouldn't be wise to leave without giving a proper goodbye.", false, 0, 1);
location seven("You are close to the path. You should go visit the library first.", false, 1, 1);
location eight("\nYou are on a path. Two steps to your east is a farmer's market stand you wish to explore.", false, 2, 1);
location nine("\nYou've arrived at the Abandoned Library. ", true, 3, 1);
location ten("You are close to the path. The eyes of the man at the town entrance follow you.", false, 4, 1);
location eleven("You lie on the outskirts of town. It wouldn't be wise to leave without giving a proper goodbye.", false, 0, 2);
location twelve("You are close to the path and the farmer's market. You should go visit the library first.", false, 1, 2);
location thirteen("You are on a path. One step to your east is a farmer's market stand you wish to explore.", false, 2, 2);
location fourteen("\n\nYou are at the entrance of a place bluntly titled: Fisherman's Town, you notice with a glance at the sign. ", false, 3, 2);
location fifteen("You stand on the path clearing in front of the town entrance.\nEnter N to advance forward", false, 4, 2);
location sixteen("You're near the farmer's market. You should go visit the library first.", false, 0, 3);
location seventeen("You are at Farmer's Market Stand 1. You wonder if there's a key piece around anywhere.", true, 1, 3);
location eighteen("\nYou are at Farmer's Market Stand 2.", true, 2, 3);
location nineteen("You are at Farmer's Market Stand 3. You wonder if there's a key piece around anywhere.", true, 3, 3);
location twenty("You are close to the path. The eyes of the man at the town entrance follow you.", false, 4, 3);
location twentyone("You lie on the outskirts of town. It wouldn't be wise to leave without giving a proper goodbye.", false, 0, 4);
location twentytwo("You are near the fisherman's manor. You should go visit the other locations first.", false, 1, 4);
location twentythree("\nYou end up at the fisherman's Manor.", true, 2, 4);
location twentyfour("You are near the fisherman's manor. You should go visit the other locations first.", false, 3, 4);
location twentyfive("You lie on the outskirts of town. It wouldn't be wise to leave without giving a proper goodbye.", false, 4, 4);

void action(string o, user &mc);
void print_location(int x, int y);

//prints description and some plot
void print_location(int x, int y){
    if (x==0 && y==0){
        cout << one.get_description();
    }
    else if (x==1 && y==0){
        cout << two.get_description();
    }
    else if (x==2 && y==0){
        cout << three.get_description();
    }
    else if (x==3 && y==0){
        cout << four.get_description();
    }
    else if (x==4 && y==0){
        cout << five.get_description();
    }
    else if (x==0 && y==1){
        cout << six.get_description();
    }
    else if (x==1 && y==1){
        cout << seven.get_description();
    }
    else if (x==2 && y==1){
        cout << eight.get_description();
    }
    else if (x==3 && y==1){
        cout << nine.get_description();
        cout << "On your way here, you picked up a pair of flimsy birthday sunglasses that were left on the ground and "
                "didn't belong to anyone near you. You dust them off, put them on, and head inside. As expected,\nit's"
                " completely empty. Save for the several shelves storing numerous volumes of various kinds.\n\nWhen you "
                "look through some of the books and their checkout cards, you discover that they only have one name on"
                " them all.\nThe fisherman seems to have been the only person to visit this library, and often, too. If"
                " the collection of his\nreadings were anything to go by. Pondering it, you figure that to even garner such"
                " a collection would take a lot of timeout of a day for a person. Belatedly, you wonder why someone"
                " who's such an integral part of a tightly knit community\nwould want to spend so much time away from"
                " them.\n\n\nSuddenly, a glimmer of gold sneaks into your plastic blue range of vision and catches your eye."
                "\nYou feel the urge to look to see where it's coming from.";
    }
    else if (x==4 && y==1){
        cout << ten.get_description();
    }
    else if (x==0 && y==2){
        cout << eleven.get_description();
    }
    else if (x==1 && y==2){
        cout << twelve.get_description();
    }
    else if (x==2 && y==2){
        cout << thirteen.get_description();
    }
    else if (x==3 && y==2){
        cout << fourteen.get_description();
        cout << "The\ndeceptively short town sign dug into the ground is strange. But when you take in the image of the man "
                "waving while\nwalking towards you, you find him even stranger.\n\nHe is in an obnoxiously large blue fin tuna "
                "mascot costume, which only his round head peeks out of, and is holding two\nskewer sticks in the enclosed hand"
                " he's waving, and a tray in the other. The skewer sticks look to have poke on them,\nand the tray seems to contain"
                " more of what he's carrying. Behind him, colorful streamers and squares of confetti line\nwalkways and vendor tents."
                "\n\n'Welcome traveller!', he exclaims as he nears. He's smiling as he does so, but there's something off about it. "
                "\nIt's stretched thin and doesn't reach his eyes.\n'You're just in time for our festival! Today, we celebrate"
                " the day our humble town was founded.', he states as \nhe turns to a building on his left.\n\nA "
                "poster that two workers are holding up from either side is unraveled to reveal a man gazing into the distance"
                " with a\ndetermined look on his face, mouth set in a straight line.\n\n'And that right there, is our founder. "
                "He's no longer with us, but we will always remember him, especially on this day.'He is solemn for a moment"
                " before perking up once more, 'But, you don't need to worry about that, haha. Please, try a\nsample! And remember"
                " to check out the vendors before you leave!'. He hands a skewer to you, but you are distracted by anoddly out"
                " of place dull structure among all the colorful tents.\n\n'What's that over there?', you ask.\n\nThe man follows your"
                " gaze and says 'Oh, that? That's the abandoned library. We all gave up on going there since they\nnever carry"
                " any books related to fish.'\n\nUnsure of what to make of that statement, you look at him in question. But his face "
                "gives no indication as to whether itwas a joke or not. In fact, he seems dead serious."
                "\n\n\nWell that's interesting. The library's just to your west, perhaps you should check it out.";
    }
    else if (x==4 && y==2){
        cout << fifteen.get_description();
    }
    else if (x==0 && y==3){
        cout << sixteen.get_description();
    }
    else if (x==1 && y==3){
        cout << seventeen.get_description();
    }
    else if (x==2 && y==3){
        cout << eighteen.get_description();
        cout << " After floundering your way through a sea of people and vendors, you stumble upon a\nrather scruffy"
                " lady manning a stand of tilapia. For a moment, she doesn't notice you there as you scan the "
                "products.\nBusy with some notepad in her hand.\n\nBut when she does, she squints at you and then "
                "exclaims, 'Hey you! You're the new employee right?'.\n\nBefore you can attempt to answer, she's"
                " dragging you by the arm and taking you across the street to a small shop. She\nseems to have "
                "partial hearing because she's unable to hear you as you protest to, in fact, not being the new "
                "employee.\n(Or maybe she can hear. You're not quite sure if it's partial or just selective) "
                "\nThe grip on your arm only lets up when you get there and she orders you to grab her clipboard "
                "from the back, before\npromptly leaving. Finding that you have no choice at the moment, you head to"
                " the back of the store.\n\n\nThere, in a dimly lit room, is the clipboard on a desk which you grab, and "
                "near the back of the room is a safe.\nYou had put your birthday glasses away for a moment, so you pull"
                " them back out again, wondering if there could be a key piece nearby.";
    }
    else if (x==3 && y==3){
        cout << nineteen.get_description();
    }
    else if (x==4 && y==3){
        cout << twenty.get_description();
    }
    else if (x==0 && y==4){
        cout << twentyone.get_description();
    }
    else if (x==1 && y==4){
        cout << twentytwo.get_description();
    }
    else if (x==2 && y==4){
        cout << twentythree.get_description();
        cout << " Like a few other sites you've just visited, it clashes with the theme of the\nentire festival"
                " drastically. It's a bit too regal-looking for the occasion, a tad overdressed. However, this "
                "isn't the\nfirst thing you notice about the residence. You're more focused on the fact that the front "
                "door is ajar; and you think\nif you hide inside, surely, no one will come looking for you"
                " here. Reluctantly, you enter.\n\nYou aren't sure what to expect when you go in, but "
                "what awaits you is a pretty, makeshift, gallery walk that you could\nhave never imagined. In a well lit hallway "
                "with scarlet red walls, are paintings of all sorts and sizes in gold carved\nframes. As you walk along the hallway, you"
                " find that, surprisingly, out of the various paintings which line the walls,\nonly three follow a distinct"
                " theme. And that theme seems to be, not 'Fish', but 'Birthday'. Since each painting depicts\nthe"
                " fisherman at a different stage in his life, blowing out birthday candles on his own, at home. In "
                "the first painting,he's a child, about four or five. In the second, a teenager. In the third, "
                "on his deathbed. But in almost every single\none, you notice he looks rather...\n\nlonely.\n\nIt is only"
                " in the last painting that he gives a genuine smile. Perhaps the knowledge of something was able to\nbring "
                "him peace in his last moments. But given the apparent lack of any sea specimen in his abode, something "
                "tells you\nthat it most likely had nothing to do with fish, for once.\n\nSeconds upon thinking this, the "
                "lights go out.\n\nSoon, you feel as though you've been moved to a different room.";
    }
    else if (x==3 && y==4){
        cout << twentyfour.get_description();
    }
    else if (x==4 && y==4){
        cout << twentyfive.get_description();
    }
    else{
        cout << "ERROR";
        exit(3);
    }
}
//used in puzzles in each setting
bool first_key_piece=false;
int drawer_choice;
bool second_key_piece=false;
int safe_combination;
bool third_key_piece=false;
int fisherman_birthday;
bool extra_hint_one=false;
bool extra_hint_two=false;
bool win = false;

int main() {
    string username;
    string option;

    cout <<"Welcome player!\nPlease enter your name:\n";
    cin >> username;

    user mc;
    mc.set_name(username);
    cout <<"\nThank you, " << mc.get_name() << ". \n\nInstructions:\nIn this game, you will have multiple opportunities to make choices for your character. \nWhenever you have the option to make a choice, you "
                                                    "may enter the command: m to access the map, n, e, s, or w to move \nalong the map, scan to look for an important object, h in case you need help, e"
                                                    " to exit, inventory to display your\ninventory, and score to view your score. \nSpecial locations with interactions will have their own instructions as well.\n\n" << "Got it? Great!\n\nNow back to our regularly "
                                                                                                                                                       "scheduled programming.\n\n\nLOADING\n\n\n";

    cout <<"...\nYou lie on some ground. Exhausted and motionless.\n\nYou feel the heat from the morning Sun burning at your eyelids."
           " Against all will drawing you back into a state of sleep,you crack open an eye. And then another. After a moment of"
           " thought, you drag yourself into a seating position and take\nin your surroundings. You sit in an empty field. Beneath "
           "your palms is fresh grass, in front of you is a path clearing\nleading into what seems to be a town in the distance, "
           "and above you is the open sky. In a perpetual state of panic, you stand up, realizing that you don't recognize where "
           "this is or how you got here.\n\nAfter taking a few short breaths, you catch something in your line of vision.\n\n\nA person."
           "\n\n\nCertainly a bit blurry from the distance, but most definitely meeting your eyes.\n\n\nAnd smiling.\n\nIn spite of the twist"
           " you feel in your gut,\nyou decide to go ask for help.\n\n";

    do{ //main loop

        print_location(mc.get_x(), mc.get_y()); //prints location each time a command is entered
        cout << "\n\nPlease enter what you would like to do\n(refer to commands 'h' or previous instructions):\n>";
        cin >> option;
        action(option, mc);

    } while (!win);

    cout<<"\nScore: " << mc.get_score();
    cout <<"\nThank you for playing! Goodbye!\n";


    return 0;
}
//commands
void action(string o, user &mc){
    if (o=="m"||o=="M"||o=="map"||o=="Map"){
        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                cout << map[i][j] << ' ';
            }
            cout << endl;
        }
        cout << "Key: '.' Empty field, 'P' Path, 'T' Town entrance, 'F' Farmer's market stand, 'M' Manor.\n";
        cout << "\nCurrent coordinates: " << mc.get_x() << "," <<mc.get_y() << endl;
    }
    else if (o=="d"||o=="drop"||o=="D"||o=="Drop"){ //newly added drop option, deletes selected item from inventory
        cout << "What item would you like to drop? Please omit any spaces from the item's name before entering.\n";
        string inventory_item;
        cin >> inventory_item;
        if (mc.dropItem(inventory_item)){
            cout << "You dropped the "<< inventory_item << "\n";
        }
        else {
            cout << "This item is not in your inventory\n" << endl;
        }
    }
    else if(o=="inventory"||o=="Inventory"){ //newly added display option for inventory; calls on function in user.h
        cout << "Inventory: " <<endl;
        mc.display_Inventory();
    }
    else if (o=="exit"||o=="Exit"){
        cout <<"Thank you for playing! Goodbye!";
        exit(1);
    }
    else if(o=="n"||o=="N"||o=="north"||o=="North"){
        if(mc.get_x() !=0){
            cout << "\nYou head North."<< endl;
            mc.set_x(mc.get_x()-1);
        }
        else{
            cout << "\nYou may not go any further North.\n"<<endl;
        }
    }
    else if(o=="s"||o=="S"||o=="south"||o=="South"){
        if(mc.get_x() !=4){
            cout << "\nYou head South.\n"<< endl;
            mc.set_x(mc.get_x()+1);
        }
        else{
            cout << "\nYou may not go any further South.\n"<<endl;
        }
    }
    else if(o=="e"||o=="E"||o=="east"||o=="East"){
        if(mc.get_y() !=4){
            cout << "\nYou head East.\n"<< endl;
            mc.set_y(mc.get_y()+1);
        }
        else{
            cout << "\nYou may not go any further East.\n"<<endl;
        }
    }
    else if(o=="w"||o=="W"||o=="west"||o=="West"){
        if(mc.get_y() !=0){
            cout << "\nYou head West.\n"<< endl;
            mc.set_y(mc.get_y()-1);
        }
        else{
            cout << "\nYou may not go any further West.\n"<<endl;
        }
    }
    else if(o=="score"||o=="Score"){
        cout << "Score: " <<mc.get_score() << "pts"<<endl; //displays accumulated points as score
    }
    else if(o=="h"||o=="H"||o=="help"||o=="Help"){
        cout << "Commands:\n-N, S, E, W to move in those directions\n"
                "\n-Map, Score to display map or score\n"
                "\n-Scan to search for a key piece\n"
                "\n-Inventory to display inventory\n"
                "\n-Drop to drop item in inventory\n"
                "\n-Exit to leave at any time\n"
                "\n-Help to see this screen again\n"
                "\nHints: \n*It's a good idea to scan any notable location\n"
                "\n*It's best to follow the path\n\n";
    }
    else if (o=="scan"||o=="Scan") {
        if (mc.get_x() == 3 && mc.get_y() == 1) {
            mc.addItem("birthdaysunglasses"); //adds string to inventory; drop does not work if item has a space, so it must be one word
            cout << "\nYou scan the area. There is a brighter glint of gold, and it's coming from one of two drawers.\nChoose a drawer by entering 1 or 2.\n";
            do { //loop that runs until first key piece is attained
                cout << "\nPlease enter what you would like to do\n(refer to commands 'h' or previous instructions):\n>"; //indicates request for user input
                cin >> drawer_choice;
                if (drawer_choice == 2) {
                    cout << "\nYou open the second drawer. Hmm...there seems to be nothing of note in this compartment. Try again.\n";
                } else if (drawer_choice == 1) {
                    cout << "\nYou open the first drawer. On first glance it seems empty. But just to make sure, you press down on one edge of the\nbottom."
                               " And what's this? The other edge lifts! You manage to pull up the slab of wood to find 1/3 of what seems to be a key,"
                               " and the numbers 514 on a slip of paper.\n";
                    first_key_piece = true; //left the boolean values to keep do while loops (mini-games) running
                    mc.addItem("firstkeypiece"); //2nd item after sunglasses
                    mc.set_score(25);
                    cout << "\nYou store both objects away for later. Perhaps now it's time to check out the farmers market vendors Mr. Blue-fin-tuna\ntold you about.\n\n";
                } else {
                    cout << "Invalid input. Try again.";
                }
            } while (!first_key_piece);
        } else if (mc.get_x() == 2 && mc.get_y() == 3) {
            for(int i = 0; i < mc.get_size(); i++){
                if(mc.get_Inventory()[i] == "birthdaysunglasses") { //since this item was added in first interaction, it unlocks this mini game
                    cout << "You scan the area.\nA familiar wink of the light suggests that there's another key piece here, "
                            "in the safe in the corner.\nEnter the correct"
                            " combination of 3 numbers (no spaces) to unlock the safe.\n";
                    do {//loop that runs until second key piece is attained
                        cout << "\nPlease enter what you would like to do\n(refer to commands 'h' or previous instructions):\n>"; //indicates request for user input
                        cin >> safe_combination;
                        if (safe_combination == 514) {
                            cout << "\nThe safe opens. Inside, there lies one more third of a key and a slip of paper with the hint: '99er.\n\n";
                            mc.addItem("secondkeypiece"); //3rd item
                            mc.set_score(25);
                            second_key_piece = true;
                        } else {
                            cout << "\nYou pull at the handle of the safe but it does not budge. Try a different combination.\n\n";
                        }
                    } while (!second_key_piece);
                    cout << "With the key piece stored away and clipboard in hand, you head out of the store and return to Stand 2 to hand it to the"
                               "\nodd lady. Immediately afterwards, you book it. Hoping she won't find you; wherever you're going.\n";
                }
                else {
                    cout << "\nYou scan the area. There's nothing of note here." << endl;
                }
            }
        } else if (mc.get_x() == 1 && mc.get_y() == 3) {
            cout << "You scan the area. There is no key piece at this stand, but there are fortune cookies. You decide to"
                       " buy one. The\nfortune cookie reads:'You, only you, who is (kind) and (helpful) deserves the best in"
                       " this world.'\nThe fortune cookie tastes like fish.\n\n";
            mc.set_score(10);
            extra_hint_one = true;
        } else if (mc.get_x() == 3 && mc.get_y() == 3) {
            cout << "You scan the area. There is no key piece at this stand, but there are pastry cakes with messages in"
                       " them on silk\nribbons. You decide to buy one. The pastry cake reads:'The fisherman was (sane)."
                       " The fisherman was (smart).'\nThe pastry cake tastes like fish.\n\n";
            mc.set_score(10);
            extra_hint_two = true;
        } else if (mc.get_x() == 2 && mc.get_y() == 4) {
            for (int i = 0; i < mc.get_size(); i++) {
                if (mc.get_Inventory()[i] == "secondkeypiece") { //since this item was added in second interaction, it unlocks this mini-game
                    mc.addItem("knife"); //4th item
                    cout << "You scan the area. The sheer darkness of the room is making it hard to see, and you don't"
                            " detect any key pieces so far.\nBut you are barely able to make out the shape of candles and a knife next to "
                            "a cake. You wonder if perhaps the previous hints can help you out here.\nIf the fisherman was"
                            " born on 05/14/1999 how old would he be today(current year: 2022)?\n";
                    do {//loop that runs until third key piece is attained
                        cout << "\nPlease enter what you would like to do\n(refer to commands 'h' or previous instructions):\n>"; //indicates request for user input
                        cin >> fisherman_birthday;
                        if (fisherman_birthday == 23) {
                            cout
                                    << "\nYou choose the candles 2 and 3 and place them gently on the cake. They light themselves and "
                                       "a draft that tickles your\nshoulder on the way in, blows them out. You watch as the candles "
                                       "fall back onto the cake and the lights turn on. You\ncan now see, clearly, a knife next to "
                                       "the cake and, through your glasses, a glint of gold through the frosting. After\ntaking the "
                                       "knife to cut and hitting metal, you pry out the last key piece. After which, you turn around"
                                       " to find\n\n...A door.\n";
                            third_key_piece = true;
                            mc.addItem("thirdkeypiece"); //5th item
                            mc.set_score(50);
                        } else {
                            cout
                                    << "\nYou choose your candles and place them on the cake but nothing happens. The lights are"
                                       " still out, and there is no sign\nof a helping hand or a hint anywhere.\nTry again.\n";
                        }
                    } while (!third_key_piece);

                cout
                        << "\nNow in front of you lies a large chrome door. In front of it, a slot layout which you assume is meant"
                           " for the key\npieces given how each slot is shaped. Above it, an embroidery encased in a long frame"
                           " showcasing a shadowy figure\nholding a fishing rod on a boat against a wheat colored background. But"
                           " the piece is noticeably incomplete with\neverything at the level of the figure's head being missing."
                           " When you place the keys in their respective slots,\nhowever, the embroidery miraculously stitches itself "
                           "complete, and the door opens. \n\nIn a whoosh of air, darkness engulfs you. The world goes silent. The only "
                           "thing visible to you is the figure from the\nembroidery. It is all that is there in front of your eyes."
                           " You are helpless to do anything except watch as rips emerge\nnear the bottom of its face and the"
                           " stitching there comes undone, as if it possessed a mind of its own. Blinding light\nseeps through the"
                           " cracks and overtakes you. Rendering you blind once more. When you can see the faintest bit, you make"
                           "\nout the shape of a person. \n\nThe fisherman welcomes you.\n\nAh, peace and quiet.";

                win = true;
                cout << "\n\n\n...\nCongratulations, you have completed 'A Fisherman's Legacy'\n";
                break;
                }
            }
        }
    }
}

