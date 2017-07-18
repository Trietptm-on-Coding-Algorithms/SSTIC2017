/*
  _________ ____________________.____________   _______________  _____________ 
 /   _____//   _____/\__    ___/|   \_   ___ \  \_____  \   _  \/_   \______  \
 \_____  \ \_____  \   |    |   |   /    \  \/   /  ____/  /_\  \|   |   /    /
 /        \/        \  |    |   |   \     \____ /       \  \_/   \   |  /    / 
/_______  /_______  /  |____|   |___|\______  / \_______ \_____  /___| /____/  
        \/        \/                        \/          \/     \/              
__________     ___________              ________      _____________.           
\______   \ ___\__    ___/__________   /  _____/_____ \______   \_ |__ _____   
 |     ___// __ \|    |_/ __ \_  __ \ /   \  ___\__  \ |       _/| __ \\__  \  
 |    |   \  ___/|    |\  ___/|  | \/ \    \_\  \/ __ \|    |   \| \_\ \/ __ \_
 |____|    \___  >____| \___  >__|     \______  (____  /____|_  /|___  (____  /
               \/           \/                \/     \/       \/     \/     \/ 
	Peter Garba (c) 2017
*/

/*
  _________ ____________________.____________   _______________  _____________ 
 /   _____//   _____/\__    ___/|   \_   ___ \  \_____  \   _  \/_   \______  \
 \_____  \ \_____  \   |    |   |   /    \  \/   /  ____/  /_\  \|   |   /    /
 /        \/        \  |    |   |   \     \____ /       \  \_/   \   |  /    / 
/_______  /_______  /  |____|   |___|\______  / \_______ \_____  /___| /____/  
        \/        \/                        \/          \/     \/              
__________     ___________              ________      _____________.           
\______   \ ___\__    ___/__________   /  _____/_____ \______   \_ |__ _____   
 |     ___// __ \|    |_/ __ \_  __ \ /   \  ___\__  \ |       _/| __ \\__  \  
 |    |   \  ___/|    |\  ___/|  | \/ \    \_\  \/ __ \|    |   \| \_\ \/ __ \_
 |____|    \___  >____| \___  >__|     \______  (____  /____|_  /|___  (____  /
               \/           \/                \/     \/       \/     \/     \/ 
	Peter Garba (c) 2017
*/

#include <stdio.h>

int TA_HMAC_KEY[]={73,39,109,32,97,110,32,97,112,112,114,111,117,118,101,100,32,84,65,32,98,117,105,108,100,101,114,32,33 };

int SSTIC_CUSTOM_KEY[]={0,17,34,51,68,85,102,119,136,153,170,187,204,221,238,255 };

int SSTIC_AES_KEY[]={95,95,95,83,83,84,73,67,95,50,48,49,55,95,95,95};

int SSTIC_PASSWORD_HMAC_KEY[]={76,85,77,123,48,113,118,89,72,58,81,73,63,75,54,125};

int Password1[] ={ 61,61,66,69,71,73,78,32,80,65,83,83,87,79,82,68,32,72,77,65,67,61,61,13,10,52,98,99,101,97,50,101,99,102,55,55,98,100,97,49,56,56,48,52,98,51,57,53,97,53,98,48,97,56,49,99,57,99,55,52,53,98,53,97,100,100,53,54,55,48,55,51,99,51,97,102,98,52,101,99,53,101,55,97,52,55,56,102,97,13,10,61,61,69,78,68,32,80,65,83,83,87,79,82,68,32,72,77,65,67,61,61 };


int PasswordSecret[] = { 61,61,66,69,71,73,78,32,80,65,83,83,87,79,82,68,32,72,77,65,67,61,61,13,10,53,48,52,56,54,49,48,56,57,100,49,48,97,56,100,53,57,48,48,99,100,102,51,98,97,100,57,54,50,48,48,52,50,56,50,101,55,51,99,50,48,100,50,100,53,97,98,57,53,98,54,55,97,101,54,98,51,51,53,54,55,52,56,98,13,10,61,61,69,78,68,32,80,65,83,83,87,79,82,68,32,72,77,65,67,61,61};


void GetTALum() {
	char LUM[16] = { 0 };

	for (int i=0;i<=0xFF;i++) {
		//int a5 = 1;
		//printf("i %i\n", i);
		int a5 = i;
		LUM[0] = a5 ^ 0x48;

		if (LUM[0] != 'L')
			continue;

		LUM[1] = a5 - 1 ^ 0x56;
		LUM[2] = a5 - 2 ^ 0x4F;
		LUM[3] = a5 - 3 ^ 0x7A;
		LUM[4] = a5 - 4 ^ 0x67;

		LUM[5] = a5 - 5 ^ -0x65;
		LUM[6] = a5 - 6 ^ -0x50;
		LUM[7] = a5 - 7 ^ -0x3B;
		LUM[8] = a5 - 8 ^ -0x2E;
		LUM[9] = a5 - 9 ^ -0x41; 
		LUM[10] = a5 - 10 ^ -0x30;
		LUM[11] = a5 - 11 ^ -0x47;
		LUM[12] = a5 - 12 ^ -0x2d;
		LUM[13] = a5 - 13 ^ -0x5E;
		LUM[14] = a5 - 14 ^ -0x60;
		LUM[15] = a5 - 15 ^ -0x78;

		printf("%i TA LUM Output: ", i);
		for (int i=0;i<16;i++) {
			printf("%c", LUM[i]);
		}
		printf("\n");
	
	}
}

//Password known
unsigned char Password[] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66 ,0x77 ,0x88,0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF};

void KeyExpansion(unsigned char Password[16], unsigned char Data[16]) {
	//Just a guess
	int s0 = (int) Data;
	int s3 = 0;
	int s5 = 0;
	int s1 = *(unsigned int *) (&Data[4]);


	int a3 = *(unsigned int *) (&Password[4]);  //a3 = b[12]
	int t5 = *(unsigned int *) (&Password[12]);

	int a5 = -337237;
	int t0 = 337237;
	int s2 = a5 -1622;
	t0 = t0 + 1621;
	int t4 = s1 + 23;
	int a2 = t5 & s2;
	a5 = a3 & t0;
	int a4 = a4 & 31;
	a5 = a5 | a2;
	a2 = 0 - a4;
	a4 = a5 >> a4;
	a5 = a4 << a2;
	a4 = a4 | a5;
	int t1 = a4 >> 24;
	t1 = t1 + 65;
	a5 = a4 >> 16;
	a2 = t1 & 255;
	a5 = a5 & 255;
	a2 = a2 + a5;
	
	t4 = *(unsigned int *) (&Password[0]);
	int t2 = *(unsigned int *) (&Password[4]);

	a2 = a2 + 72;
	int a0 = a4 >> 8;
	int a1 = a2 & 255;
	a0 = a0 & 255;
	a5 = s1 & 19;
	a1 = a1 + a0;
	int a6 = t4 & t0;
	a0 = t2 & s2;
	a5 = a5 & 31;
	a1 = a1 & 79;
	a6 = a6 | a0;
	int a7 = 0 - a5;
	a0 = a1 & 255;
	a4 = a4 & 255;
	a5 = a6 >> a5;
	a4 = a0 + a4;
	a6 = a6 << a7;
        a5 = a5 | a6;
        a0 = a4 + 86;
        a6 = a0 & 255;
        a4 = a5 >> 24;
        a6 = a6 + a4;
        a6 = a6 + 93;
        a4 = a5 >> 16;
        a7 = a6 & 255;
        a4 = a4 & 255;
        a7 = a7 + a4;
        a7 = a7 + 100;
        int t6 = a5 >> 8;
        int t3 = a7 & 0xFF;
        t6 = t6 & 0xFF;
        a4 = s1 + 0x11;
        t3 = t3 + t6;
        t5 = t5 & t0;
        a4 = a4 & 0x1F;
        t3 = t3 + 0x6B;
        a3 = a3 & s2;
        a3 = a3 | t5;
        t6 = 0 - a4;
        t5 = t3 & 0xFF;
        a5 = a5 & 0xFF;
        a5 = t5 + a5;
        a4 = a3 >> a4;
	a3 = a3 << t6;
        a4 = a4 | a3;
        a3 = a5 + 0x72;
        t5 = a3 & 0xFF;
        a5 = a4 >> 0x18;
        t5 = t5 + a5;
        t5 = t5 + 0x79;
        a5 = a4 >> 0x10;
        t6 = t5 & 0xFF;
        a5 = a5 & 0xFF;
        t6 = t6 + a5;
        t6 = t6 + 0x80;
        a5 = a4 >> 8;
	int s4 = t6 & 0xFF;
        a5 = a5 & 0xFF;
        s4 = s4 + a5;
        s1 = s1 + 0xD;
        a5 = t4 & s2;
        t0 = t2 & t0;
        s1 = s1 & 0x1F;
        s4 = s4 + 0x87;
        a5 = a5 | t0;
        t4 = 0 - s1;
        t0 = s4 & 0xFF;
        a4 = a4 & 0xFF;
        s1 = a5 >> s1;
        a4 = t0 + a4;
        a5 = a5 << t4;
        a5 = s1 | a5;
        t0 = a4 + 0x8E;
        t2 = t0 & 0xFF;
        a4 = a5 >> 0x18;
        t2 = t2 + a4;
        t2 = t2 + 0x95;
        a4 = a5 >> 0x10;
        s1 = t2 & 0xFF;
        a4 = a4 & 0xFF;
        s1 = s1 + a4;
        s1 = s1 + 0x9C;
        a4 = a5 >> 8;
        s2 = s1 & 0xFF;
        a4 = a4 & 0xFF;
        s2 = s2 + a4;
        s2 = s2 + 0xA3;
        a4 = s2 & 0xFF;
        a5 = a5 & 0xFF;
        a5 = a5 + a4;
        int s6 = s0 + 8;
        a4 = s3 + 8;
        t4 = s3 + 0xC;
        s5 = s0 + 0xC;
        a5 = a5 + 0xAA;
        //sltu           t4 = s6, t4
	((unsigned) t6 < (unsigned) t4) ? (t4 = 1) : (t4 = 0);
        //sltu           s5 = a4, s5
	((unsigned) a4 < (unsigned) s5) ? (s5 = 1) : (s5 = 0);
        int s7 = a3 & 0xFF;
        t1 = t1 & 0xFF;
        a2 = a2 & 0xFF;
        a1 = a1 & 0xFF;
        a0 = a0 & 0xFF;
        a6 = a6 & 0xFF;
        a7 = a7 & 0xFF;
        t3 = t3 & 0xFF;
        t5 = t5 & 0xFF;
        t6 = t6 & 0xFF;
        s4 = s4 & 0xFF;
        t0 = t0 & 0xFF;
        t2 = t2 & 0xFF;
        s1 = s1 & 0xFF;
        s2 = s2 & 0xFF;
	a5 = a5 & 0xFF;
        t4 = t4 ^ 1;
        a3 = s5 ^ 1;

	//Store
	Password[15] = t1;
	Password[14] = a2;
	Password[13] = a1;
	Password[12] = a0;
	Password[11] = a6;
	Password[10] = a7;
	Password[9] = t3;
	Password[8] = s7;
	Password[7] = t5;
	Password[6] = t6;
	Password[5] = s4;
	Password[4] = t0;
	Password[3] = t2;
	Password[2] = s1;
	Password[1] = s2;
	Password[0] = a5;

	printf("Password1: ");
	for(int i=0;i<16;i++) {
		printf("%02X", Password[i]);
	}
	printf("\n");

	printf("Password1: ");
	for(int i=0;i<16;i++) {
		printf("%i ", Password[i]);
	}
	printf("\n");
} 
int main(void) {
	printf("TA_HMAC_KEY:\n");
	
	for (int i=0;i<sizeof(TA_HMAC_KEY) /4;i++) {
		printf("%c",TA_HMAC_KEY[i]);
	}

	printf("\n\n");


	printf("SSTIC_CUSTOM_KEY:\n");

       	for (int i=0;i<sizeof(SSTIC_CUSTOM_KEY) / 4;i++) {
                printf("%c",SSTIC_CUSTOM_KEY[i]);
        }

	printf("\n\n");

	printf("SSTIC_AES_KEY:\n");

       	for (int i=0;i<sizeof(SSTIC_AES_KEY) /4;i++) {
                printf("%c",SSTIC_AES_KEY[i]);
        }

	printf("\n\n");

	printf("SSTIC_PASSWORD_HMAC_KEY:\n");

       	for (int i=0;i<sizeof(SSTIC_PASSWORD_HMAC_KEY) /4;i++) {
                printf("%c",SSTIC_PASSWORD_HMAC_KEY[i]);
        }

	printf("\n\n");

	printf("Password1:\n");

       	for (int i=0;i<sizeof(Password1) /4;i++) {
                printf("%c",Password1[i]);
        }

	printf("\n\n");

	printf("PasswordSecret:\n");

       	for (int i=0;i<sizeof(PasswordSecret) /4;i++) {
                printf("%c",PasswordSecret[i]);
        }

	printf("\n\n");

	//LUM stuff
	GetTALum();

	//Key expansion 1
	unsigned char Data[16] = {0  };
	KeyExpansion(Password, Data);
	
	return 0;

}
