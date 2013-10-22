/*******************************************
  * Author: C1C Ethan Snyder
  * Created: 13 Oct 2013
  * Description: A short program to demonstrate the basics of a game engine for pong.
*******************************************/
#include <msp430.h> 
//#include pong.h   pong.h has more game engine stuff
#define WINDOW_W 0x40
#define WINDOW_H 0x20
typedef struct  {
	int xp, yp, xv, yv, rad;
    } ball;
ball upDatedBall(ball currentball);
ball CollisionTop(ball currentball);
ball CollisionBottom(ball currentball);
ball CollisionRight(ball currentball);
ball CollisionLeft(ball currentball);
ball createBall(int xp, int yp, int xv, int yv, int rad);










    int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	

    	ball myball=createBall(10,10,1,1,2);

while (1){
    myball=upDatedBall(myball);
}









ball createBall(int xp, int yp,int xv,int yv,int rad){
		ball myball;
		myball.xp=xp;
		myball.yp=yp;
		myball.xv=xv;
		myball.yv=yv;
		myball.rad=rad;
		return (myball);


	}

ball upDatedBall(ball myMovingBall){
	    myMovingBall.xp+=myMovingBall.xv;
		myMovingBall.yp+=myMovingBall.yv;

		myMovingBall= CollisionTop(myMovingBall);
		myMovingBall= CollisionBottom(myMovingBall);
		myMovingBall= CollisionRight(myMovingBall);
		myMovingBall= CollisionLeft(myMovingBall);




		return (myMovingBall);


}














ball CollisionTop(ball currentball){
    	if(currentball.yp+currentball.rad >= WINDOW_H){
    			currentball.yv=currentball.yv*-1;
    			return currentball;
    	}

    	return currentball;

    }

ball CollisionBottom(ball currentball){
    	if(currentball.yp+currentball.rad <= 0){
    			currentball.yv=currentball.yv*-1;
    			return currentball;
    	}

    	return currentball;

    }

ball CollisionRight(ball currentball){
    	if(currentball.xp+currentball.rad >= WINDOW_W){
    			currentball.xv=currentball.xv*-1;
    			return currentball;
    	}

    	return currentball;

    }

ball CollisionRight(ball currentball){
    	if(currentball.xp+currentball.rad <= 0){
    			currentball.xv=currentball.xv*-1;
    			return currentball;
    	}

    	return currentball;

    }















}
