#include <iostream>
using namespace std;
class Truck {
 private:
  int id;

 public:
  Truck(int id) { this->id = id; }
  Truck() { this->id = 0; }
  int getid() { return id; }
};
Truck garage[100];  // an array is used as a stack to implement the
                    // functionality of garage int
int n = 100;
int top = -1;
int onRoad(Truck t_id)  // will tell if the truck t_id is at the gate of the
                        // garage or not
{
  if (garage[top].getid() == t_id.getid())
    return 1;
  else
    return 0;
}
void enter_Garage(Truck t) {
  if (top >= n - 1)
    cout << "\nNo more space in the Garage" << endl;
  else {
    top++;
    garage[top] = t;
  }
}
void exit_Garage(Truck t) {
  if (top <= -1)
    cout << "\nNo Trucks in the Garage" << endl;
  else {
    if (onRoad(t) == 1) {
      cout << "\nThe Truck with id " << t.getid() << " moved out " << endl;
      top--;
    } else {
      cout << "\nTruck " << t.getid() << " not near Garage door" << endl;
    }
  }
}
void show_Trucks() {
  if (top >= 0) {
    cout << "\nTrucks in the Garage are :";
    for (int i = top; i >= 0; i--)
      cout << "\nTruck " << garage[i].getid() << " ";
    cout << endl;
  } else
    cout << "\nGarage is empty";
}
int main() {
  Truck t1(2);
  Truck t2(4);
  Truck t3(6);
  Truck t4;
  enter_Garage(t1);
  enter_Garage(t2);
  enter_Garage(t3);
  enter_Garage(t4);
  show_Trucks();
  exit_Garage(t1);
  exit_Garage(t4);
  show_Trucks();
}