#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h> // for rand()

void showInfo(int option) {
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, BLACK);
    bar(50, 270, 600, 390); // Clear info area before showing

    outtextxy(50, 275, "Info:");

    switch(option) {
        case 1:
            outtextxy(50, 295, "Elements:");
            outtextxy(50, 315, "N2 = Nitrogen gas molecule");
            outtextxy(50, 335, "H2 = Hydrogen gas molecule");
            outtextxy(50, 355, "NH3 = Ammonia molecule");
            break;
        case 2:
            outtextxy(50, 295, "Haber Process:");
            outtextxy(50, 315, "Synthesis of ammonia from nitrogen and hydrogen gases");
            outtextxy(50, 335, "Occurs at high temperature, pressure and with catalyst");
            break;
        case 3:
            outtextxy(50, 295, "Examples & Usage:");
            outtextxy(50, 315, "Used widely in fertilizer production");
            outtextxy(50, 335, "Essential to agricultural industry worldwide");
            break;
        default:
            outtextxy(50, 295, "Invalid option!");
    }
}

int main() {
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Draw reactor
    rectangle(250, 100, 450, 250);
    outtextxy(280, 80, "Haber Process Reactor");

    // Show reaction inside box
    outtextxy(260, 110, "N2 + 3H2 -> 2NH3");

    // Molecule starting positions
    int n2_x = 50, n2_y = 130;
    int h2_x = 50, h2_y = 200;
    int nh3_x = 450, nh3_y = 175;

    // Draw input labels below molecules
    outtextxy(n2_x - 20, n2_y + 10, "N2");
    outtextxy(h2_x - 20, h2_y + 10, "H2");

    // Draw output label below ammonia molecule
    outtextxy(nh3_x - 20, nh3_y + 10, "NH3");

    int n2_curr_x = n2_x;
    int n2_curr_y = n2_y;
    int h2_curr_x = h2_x;
    int h2_curr_y = h2_y;

    randomize();

    // Animate N2 and H2 molecules diffusing into the reactor
    for (int i = 0; i <= 200; i += 5) {
        int n2_diffuse_y = n2_curr_y + (rand() % 11) - 5;
        int h2_diffuse_y = h2_curr_y + (rand() % 11) - 5;

        setcolor(BLUE);
        setfillstyle(SOLID_FILL, BLUE);
        fillellipse(n2_curr_x, n2_diffuse_y, 5, 5);
        outtextxy(n2_curr_x - 5, n2_diffuse_y + 10, "N2");

        setcolor(RED);
        setfillstyle(SOLID_FILL, RED);
        fillellipse(h2_curr_x, h2_diffuse_y, 5, 5);
        outtextxy(h2_curr_x - 5, h2_diffuse_y + 10, "H2");

        delay(80);

        setcolor(BLACK);
        setfillstyle(SOLID_FILL, BLACK);
        fillellipse(n2_curr_x, n2_diffuse_y, 5, 5);
        fillellipse(h2_curr_x, h2_diffuse_y, 5, 5);

        n2_curr_x += 5;
        h2_curr_x += 5;
        n2_curr_y = n2_diffuse_y;
        h2_curr_y = h2_diffuse_y;
    }

    // Show reaction inside reactor with label
    for (int i = 0; i <= 100; i += 5) {
        setcolor(YELLOW);
        setfillstyle(SOLID_FILL, YELLOW);
        fillellipse(350, 175, 7, 7);
        outtextxy(350 - 20, 175 + 15, "Reaction");
        delay(120);

        setcolor(BLACK);
        setfillstyle(SOLID_FILL, BLACK);
        fillellipse(350, 175, 7, 7);
        outtextxy(350 - 20, 175 + 15, "        ");
    }

    // Animate NH3 molecule leaving reactor with label
    for (int i = 0; i <= 100; i += 5) {
        setcolor(GREEN);
        setfillstyle(SOLID_FILL, GREEN);
        fillellipse(nh3_x + i, nh3_y, 7, 7);
        outtextxy(nh3_x + i - 10, nh3_y + 10, "NH3");

        delay(80);

        setcolor(BLACK);
        setfillstyle(SOLID_FILL, BLACK);
        fillellipse(nh3_x + i, nh3_y, 7, 7);
        outtextxy(nh3_x + i - 10, nh3_y + 10, "    ");
    }

    // Final NH3 molecule formed with label
    setcolor(GREEN);
    setfillstyle(SOLID_FILL, GREEN);
    fillellipse(nh3_x + 100, nh3_y, 10, 10);
    outtextxy(nh3_x + 120, nh3_y - 10, "NH3 formed");

    // Show menu options for user to choose info
    setcolor(WHITE);
    outtextxy(50, 400, "Press 1 for Elements info");
    outtextxy(50, 420, "Press 2 for Process info");
    outtextxy(50, 440, "Press 3 for Examples & Usage");

    int ch;
    while (true) {
        ch = getch();
        if (ch == '1' || ch == '2' || ch == '3') {
            showInfo(ch - '0');
        }
        else if (ch == 27) { // ESC key to exit
            break;
        }
    }

    getch();
    closegraph();
    return 0;
}
