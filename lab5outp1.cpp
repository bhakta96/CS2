// Asav Bhakta
// Lab5outp1
// this program will move ball by speed the user decide to put and change size.
#include<iostream>
#include <ctime>
#include"graph1.h"

using namespace std;

class BallAnimation
{
private:
	int x;
	int y;
	int ball_obj;
	int speed;
	int radius;
	int duration;

public:
	BallAnimation();
	void setX(int x_val);
	int getX();
	void setY(int y_val);
	int getY();
	void setRadius(int radius_val);
	int getRadius();
	void setSpeed(int speed_val);
	int getSpeed();
	void setDuration(int duration_val);
	int getDuration();
	void display();
	void move();
	void reset();
};

BallAnimation::BallAnimation()
{
	x = 70;
	y = 70;
	ball_obj = 0;
	speed = 1;
	radius = 15;
	duration = 0;
}
void BallAnimation::setX(int x_val)
{
	// Left Edge
	if (x_val - radius < 50)
		x = 50 + radius;
	//Right Edge
	else if (x_val + radius > 600)
		x = 600 - radius;

}
int BallAnimation::getX()
{
	return x;
}
void BallAnimation::setY(int y_val)
{
	//Top Edge
	if (y_val - radius < 50)
		y = 50 + radius;
	//Bottom Edge
	else if (y_val + radius > 440)
		y = 440 - radius;

}
int BallAnimation::getY()
{
	return y;
}
void BallAnimation::setRadius(int radius_val)
{
	if (radius_val <= 5)
	{
		radius = 5;
	}
	else if (radius_val >= 70)
	{
		radius = 70;
	}
}
int BallAnimation::getRadius()
{
	return radius;
}
void BallAnimation::setSpeed(int speed_val)
{
	if (speed_val <= 0)
	{
		speed = 0;
	}
	else if (speed_val >= 30)
	{
		speed = 30;
	}
}
int BallAnimation::getSpeed()
{
	return speed;
}
void BallAnimation::setDuration(int duration_val)
{
	if (duration_val <= 30)
	{
		duration = 30;
	}
	else if (duration_val >= 60)
	{
		duration = 60;
	}
}
int BallAnimation::getDuration()
{
	return duration;
}
void BallAnimation::display()
{
	int object = 0;
	// create box
	drawLine(50, 50, 600, 50, 2);
	drawLine(50, 50, 50, 440, 2);
	drawLine(50, 440, 600, 440, 2);
	drawLine(600, 50, 600, 440, 2);

	ball_obj = drawCircle(15, 70, 70);
	setColor(ball_obj, 255, 0, 0);
	
}
void BallAnimation::move()
{
	int end_time = 0;
	int start_time = 0;
	int new_ball = 0;
	int x_coord = 1;
	int y_coord = 1;

	
	start_time = time(0);
	do
	{
		
		end_time = time(0);
		Sleep(10);
		//Check the time
		
		
		gout << setPos(250, 455) << "Current Speed is: " << speed << endg;
		gout << setPos(250, 467) << "Current Radius is: " << radius << endg;
		gout << setPos(250, 477) << "Remaining Time is: " << ( end_time - start_time - duration) << endg;

		//Check for end of animation
	if (end_time - start_time >= duration)
		{
			return;
		}

		//Check for arrows
		//Increase/Decrease speed
		if (up())
		{
			setSpeed(++speed);
		}

		if (down())
		{
			setSpeed(--speed);
		}


		//Increase/Decrease radius
		if (right())
		{
			setRadius(--radius);
			new_ball = drawCircle(radius, x, y);
			setColor(new_ball, 255, 0, 0);
			replaceObject(ball_obj, new_ball);
			ball_obj = new_ball;
		}

		if (left())
		{
			setRadius(++radius);
			new_ball = drawCircle(radius, x, y);
			setColor(new_ball, 255, 0, 0);
			replaceObject(ball_obj, new_ball);
			ball_obj = new_ball;
		}

		//Check the boundary condition for x and reverse x if left/right collision
		//ADD YOUR CODE HERE

		if (x + radius == 600 )
		{
			// right side collison
			
			do{
				end_time = time(0);
				Sleep(10);

				gout << setPos(250, 455) << "Current Speed is: " << speed << endg;
				gout << setPos(250, 467) << "Current Radius is: " << radius << endg;
				gout << setPos(250, 477) << "Remaining Time is: " << (end_time- start_time - duration) << endg;

				x -= speed;
				y -= speed;

				if (up())
				{
					setSpeed(++speed);
				}

				if (down())
				{
					setSpeed(--speed);
				}


				//Increase/Decrease radius
				if (right())
				{
					setRadius(--radius);
					new_ball = drawCircle(radius, x, y);
					setColor(new_ball, 255, 0, 0);
					replaceObject(ball_obj, new_ball);
					ball_obj = new_ball;
				}

				if (left())
				{
					setRadius(++radius);
					new_ball = drawCircle(radius, x, y);
					setColor(new_ball, 255, 0, 0);
					replaceObject(ball_obj, new_ball);
					ball_obj = new_ball;
				}
				
				new_ball = drawCircle(radius, x, y);
				setColor(new_ball, 255, 0, 0);
				replaceObject(ball_obj, new_ball);
				ball_obj = new_ball;
				moveObject(ball_obj, x, y);
			} while (y + radius > 80);
		}

			// left side collison
		 else if (x + radius  == 80)
		{
			x += speed;
			
			if (up())
			{
				setSpeed(++speed);
			}

			if (down())
			{
				setSpeed(--speed);
			}


			//Increase/Decrease radius
			if (right())
			{
				setRadius(--radius);
				new_ball = drawCircle(radius, x, y);
				setColor(new_ball, 255, 0, 0);
				replaceObject(ball_obj, new_ball);
				ball_obj = new_ball;
			}

			if (left())
			{
				setRadius(++radius);
				new_ball = drawCircle(radius, x, y);
				setColor(new_ball, 255, 0, 0);
				replaceObject(ball_obj, new_ball);
				ball_obj = new_ball;
			}
			
			new_ball = drawCircle(radius, x, y);
			setColor(new_ball, 255, 0, 0);
			replaceObject(ball_obj, new_ball);
			ball_obj = new_ball;
			moveObject(ball_obj, x, y);
		}

		

		//Check the boundary condition for y and reverse y if top/bottom collision
		//ADD YOUR CODE HERE
		
		// bottom collison
		 else if (y + radius == 440)
		{
			
			do{
				end_time = time(0);
				Sleep(10);

				gout << setPos(250, 455) << "Current Speed is: " << speed << endg;
				gout << setPos(250, 467) << "Current Radius is: " << radius << endg;
				gout << setPos(250, 477) << "Remaining Time is: " << (end_time - start_time - duration) << endg;

				y -= speed;
				x += speed;

				if (up())
				{
					setSpeed(++speed);
				}

				if (down())
				{
					setSpeed(--speed);
				}


				//Increase/Decrease radius
				if (right())
				{
					setRadius(--radius);
					new_ball = drawCircle(radius, x, y);
					setColor(new_ball, 255, 0, 0);
					replaceObject(ball_obj, new_ball);
					ball_obj = new_ball;
				}

				if (left())
				{
					setRadius(++radius);
					new_ball = drawCircle(radius, x, y);
					setColor(new_ball, 255, 0, 0);
					replaceObject(ball_obj, new_ball);
					ball_obj = new_ball;
				}
			
				new_ball = drawCircle(radius, x, y);
				setColor(new_ball, 255, 0, 0);
				replaceObject(ball_obj, new_ball);
				ball_obj = new_ball;
				moveObject(ball_obj, x, y);
				
			} while (x + radius < 600);
			
		}


		// top collison 
		 else if (y + radius == 80)
		{
			
			do{
				end_time = time(0);
				Sleep(10);

				gout << setPos(250, 455) << "Current Speed is: " << speed << endg;
				gout << setPos(250, 467) << "Current Radius is: " << radius << endg;
				gout << setPos(250, 477) << "Remaining Time is: " << (end_time - start_time - duration) << endg;

				y += speed;
				x -= speed;

				if (up())
				{
					setSpeed(++speed);
				}

				if (down())
				{
					setSpeed(--speed);
				}


				//Increase/Decrease radius
				if (right())
				{
					setRadius(--radius);
					new_ball = drawCircle(radius, x, y);
					setColor(new_ball, 255, 0, 0);
					replaceObject(ball_obj, new_ball);
					ball_obj = new_ball;
				}

				if (left())
				{
					setRadius(++radius);
					new_ball = drawCircle(radius, x, y);
					setColor(new_ball, 255, 0, 0);
					replaceObject(ball_obj, new_ball);
					ball_obj = new_ball;
				}

				
				new_ball = drawCircle(radius, x, y);
				setColor(new_ball, 255, 0, 0);
				replaceObject(ball_obj, new_ball);
				ball_obj = new_ball;
				moveObject(ball_obj, x, y);
				
			} while (x + radius  > 80);
		}

		 
		//Increment (or decrement) x/y values based on speed and direction
		 else if(x<=600 && y<=440)
		{
		x+= speed;
		y+= speed;
		}

			//Move the ball
			moveObject(ball_obj, x, y);
	}while (end_time - start_time <= duration);

}
void BallAnimation::reset()
{
	clearGraphics();
	x = 70;
	y = 70;
	ball_obj = 0;
	speed = 1;
	radius = 15;
	duration = 0;

}

int main()
{
	int seconds;
	char repeat = 0;
	do{
		BallAnimation ball;
		displayGraphics();
		srand(time(0));

		cout << "Enter the duration (in seconds) that the animation runs: ";
		cin >> seconds;

		ball.setDuration(seconds);
		ball.display();
		ball.move();

		cout << "Replay (y/n)? ";
		cin >> repeat;

		if (repeat == 'Y' || repeat == 'y')
		{
			ball.reset();
		}
	} while (repeat == 'Y' || repeat == 'y');
}