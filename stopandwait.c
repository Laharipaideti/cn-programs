#include <stdio.h>

int timer = 0, wait_for_ack = -1, frameQ = 0, cansend = 1, t = 0;


int sender(int time, int frame[]);
int recv(int time);

int main() {
    int i, j;
    int frame[5];

    printf("===== Stop-and-Wait ARQ Simulation =====\n");
    printf("Enter the time when data frame will be ready (3 values):\n");
    for (j = 0; j < 3; j++) {
        scanf("%d", &frame[j]);  // store frame ready times
    }

    
    for (i = 0; i < 10; i++) {
        printf("\n---- TIME = %d ----\n", i);
        sender(i, frame);
        recv(i);
    }

    return 0;
}

int sender(int time, int frame[]) {
    wait_for_ack++;

    
    if (time == frame[t]) {
        frameQ++;
        t++;
    }

    if (frameQ == 0)
        printf("Sender: No frame to send at time %d\n", time);

    if (frameQ > 0 && cansend == 1) {
        printf("Sender: Frame sent at time %d\n", time);
        cansend = -1;
        frameQ--;
        timer = 1;
    }

    if (frameQ > 0 && cansend == -1)
        printf("Sender: Frame in queue waiting at time %d\n", time);

    printf("Sender: frameQ=%d, timer=%d\n", frameQ, timer);
    return 0;
}

int recv(int time) {
    if (timer > 0) {
        timer++;
    }

    if (timer == 3) { 
        printf("Receiver: Frame arrived at time %d\n", time);
        wait_for_ack = 0;
        timer = 0;
        cansend = 1;
        printf("Receiver: ACK sent at time %d\n", time);
    } else if (timer > 0) {
        printf("Receiver: Waiting for frame at time %d\n", time);
    }

    return 0;
}