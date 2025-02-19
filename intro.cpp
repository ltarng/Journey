#include"console.h"
void prologue()
{
    printf("\n\n\t\t\t");
    setColor(BlueOnW);
    printf(" %c %c %c %c Journey %c %c %c %c \n\n",6,5,4,3,3,4,5,6);/*字元4:菱形*/
    setColor(White);
    printf("\n\t諸神之城，伊嵐翠。它曾是如此美麗，閃亮著無比光輝。"
           "\n\t而居住其中的伊嵐翠人更是美麗得無法逼視。"
           "\n\t他們彷彿是力量的結合體，被視為創造奇蹟的諸神。\n");
    Sleep(5500);
    printf("\n\t直到有一天，一切都變了樣......"
           "\n\t諸神之城在一夕之間崩毀，化為死亡之城。"
           "\n\t詛咒會在任何時刻來臨，將任何人變成永恆活著的『屍體』。\n");
    Sleep(4500);
    printf("\n\t這可怕的變化，使得其他地區的居民將伊嵐翠稱為「被詛咒之城」。\n");
    Sleep(3500);
    printf("\n\t身為一名勇者，你必須想辦法找出這「災罰」降臨的原因。"
           "\n\t於是你動身前往永恆森林的深處尋找神龍王，詢問拯救伊嵐翠的辦法。\n"
           "\n\t在前往永恆森林的路上你將會遭遇敵人，必須將敵人擊退才能夠繼續前進。\n\n");
    Sleep(2000);
    system("pause");
    system("cls");
}
void introduction_battle()
{
    setColor(Yellow);
    printf("\t\t\t*****戰鬥系統解說*****\n");
    setColor(White);
    printf("\n\t等級由低到高分別為：\n"
           "\n\t霍依德、半獸人、克羅斯怪物以及黑龍-阿姆塔特\n");
    printf("\n\t遇到的怪物將會採隨機登場制，就是指每種怪物都可能出現。\n"
           "\n\t由於受到伊嵐翠崩毀的影響，勇者使用魔法的狀況會時好時壞。\n"
           "\n\t而使用狀況的好壞，依照玩家在戰鬥開始前進行終極密碼遊戲的結果。\n"
           "\n\t玩家所猜的數字距離答案越接近，可以使用的魔法威力越強。\n\n");
    Sleep(2000);
    system("pause");
    system("cls");
}
void guide()
{
    setColor(Yellow);
    printf("\t\t\t*****遊戲基本導覽*****\n");
    setColor(White);
    printf("\n\t\t使用鍵盤的上下左右來控制人物移動。\n"
           "\n\t\tN代表NPC、H代表梯子、T為提示、D代表神龍王\n");
    printf("\n\t\t在地圖中按下Enter鍵可以再看一次圖示。\n"
           "\n\t\t另外，還有一些特別的圖示。\n"
           "\n\t\t至於會遇到什麼事件，就自行去發掘吧!\n"
           "\n\t\t祝您有個愉快的冒險!!\n\n");
    Sleep(2000);
    system("pause");
    system("cls");
}
void introduction_ultimate_code()/*introduce ultimatecode rule*/
{
    setColor(Red);
    printf("\t\t\t     警告：遇到怪物!!\n\n");
    setColor(Yellow);
    printf("\t\t\t*****終極密碼遊戲規則*****\n");
    setColor(White);
    printf("\n\t在戰鬥開始前，您必須先玩終極密碼來決定您的血量和攻擊力。\n"
           "\n\t一開始，系統將會預設一個隨機的數字，玩家需從1-50猜一個數字。\n"
           "\n\t頭和尾的數字不會是答案。\n"
           "\n\t若答案是26，而玩家猜的是11，系統將會顯示答案在「11-50之間」。\n"
           "\n\t若接下來玩家猜30，系統將會顯示答案在「11-30之間」。\n"
           "\n\t由此列推，直到2次機會全部用完。\n\n");
    Sleep(2000);
    system("pause");
    system("cls");
}

