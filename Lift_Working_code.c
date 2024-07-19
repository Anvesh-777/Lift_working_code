#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
	#define GROUND 0
	#define FIRST 1
	#define SECOND 2
	#define Init() ((void *)0)
	#define Cls_() printf("\033[2J\033[H");
    #define floor_check() { \
        int floor = rand() % 100; \
            if (floor == 0) { \
            int *current_floor_ = Init(); \
            *current_floor_ = SECOND ; \
        } \
    }
    void move_lift(int *current_floor, int target_floor);
    int validate_lift_move(int start, int dst);
#ifndef UNT_TEST
  // #define UNT_TEST
#endif
 
#ifdef UNT_TEST
    static int result_count =0;
    static int uCurrent_floor = GROUND;
    const int cUTest = 100;
    int uLift_floor = GROUND; 
	int uTarget_floor = GROUND;
    static void validate(int from, int to)
	{
	    if(from == to)
	      result_count++;
	}
	static int get_ut_result() {  return result_count; }
	void execute_ut()
	{
	    printf("**** Bro move lift *** \n");
	           static int i = 0;
	           int k = 0;
	           do {
	               printf("\n i = %d  ", i);
	               k =(rand() % 3);
    	           uTarget_floor = k;
    	           printf("lift_floor = %d , target_floor = %d \n", uLift_floor, uTarget_floor);
    	           if(validate_lift_move(uLift_floor,uTarget_floor))
	            	   move_lift(&uLift_floor, uTarget_floor);
    	           i++;
    	           validate(uLift_floor, uTarget_floor);
    	           floor_check();
	           } while(i != (cUTest));
	           if(get_ut_result() == cUTest)
	                printf("\n All %d test cases Passed, Well Done!! great Success!! ", cUTest);
	           else 
	                printf("\n Only  %d test cases Passed!! Look out for bug", get_ut_result());
	           result_count = 0;
	           i= 0;
	}
#endif
 
	void move_lift(int *current_floor, int target_floor) {
	    if (*current_floor < target_floor) {
	        printf("Lift moving up...\n");
	        while (*current_floor < target_floor) {
	            (*current_floor)++;
	        }
	    } else if (*current_floor > target_floor) {
	        printf("Lift moving down...\n");
	        while (*current_floor > target_floor) {
	            (*current_floor)--;
	        }
	    }
	    printf("Lift reached  %d floor .", *current_floor);
	}
	int validate_lift_move(int start, int dst)
    {   
        int ret = 1; 
        if (dst < GROUND || dst > SECOND) { 
        printf("Invalid floor number. Please enter a valid floor number.\n");
        return 0; 
    }
    if (dst == start) { 
        printf("Lift is already at the destination floor.\n");
        return 0; 
    } 
    return ret;
}

	int main() {
	    srand(time(NULL));
	    int lift_floor = GROUND; 
	    int target_floor = GROUND;
	    char input;
	    Cls_()
	    do  {
	       #ifndef UNT_TEST
	        printf("press \n \
	                0 for Ground, \n \
	                1 for 1st floor, \n \
	                2 for 2nd floor: \n");
	           	printf("Where to go  : ");
	        	scanf("%d",&target_floor);
	                if(validate_lift_move(lift_floor,target_floor))
                    {
                        move_lift(&lift_floor, target_floor);
                        printf("Lift at %d floor .", lift_floor); 
                    }
                    else
                        printf("Lift at %d floor .", lift_floor);
	       #else
	          	 execute_ut();
	       #endif
	       while (getchar() != '\n');
	       input = getchar();
	       Cls_()
	    } while (input != ' ');
	    printf("Lift simulation ended.\n");
	    return 0;
	}