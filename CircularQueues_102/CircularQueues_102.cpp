#include <iostream>
using namespace std;

class Queues {						//membuat class queues
	int FRONT, REAR, max = 5;
	int queues_array[5];

public:									//constructor
	Queues() {
		FRONT = -1;
		REAR = -1;
	}

	void insert() {					//membuat method insert
		int num;
		cout << "Enter a number: ";
		cin >> num;
		cout << endl;

		//cek apakah antrian penuh
		if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1)) {
			cout << "\nQueue Overflow\n";
			return;
		}

		//cek apakah antrian kosong
		if (FRONT == -1) {
			FRONT = 0;
			REAR = 0;
		}
		else {
			//jika rear berada di posisi terakhir array, kembali ke awal array
			if (REAR == max - 1)
				REAR = 0;
			else
				REAR = REAR + 1;
		}
		queues_array[REAR] = num;
	}

	void remove() {		//method remove
		// cek apakah antrian kosong
		if (FRONT == -1) {
			cout << "Queue Underflow\n";
			return;
		}
		cout << "\nThe Element deleted from the the queue is : " << queues_array[FRONT] << "\n";

		//cek jika antrian hanya memiliki satu elemen
		if (FRONT == REAR) {
			FRONT = -1;
			REAR = -1;
		}
		else {
			//JIka elemen yang dihapus berada di posisi terakhir array, kembali ke awal array
			if (FRONT == max - 1)
				FRONT = 0;
			else
				FRONT = FRONT + 1;
		}
	}

	void display() {			//method display
		int FRONT_position = FRONT;
		int REAR_position = REAR;

		//cek apakah antrian kosong
		if (FRONT == -1) {
			cout << "Queue is Empty\n";
			return;
		}

		cout << "\nElement in the queue are...\n";

		//jika FRONT_position <= REAR_position, iterasi dari FRONT hingga REAR
		if (FRONT_position <= REAR_position) {
			while (FRONT_position <= REAR_position) {
				cout << queues_array[FRONT_position] << "	";
				FRONT_position++;
			}
			cout << endl;
		}
		else {
			// Jika FRONT_position > REAR_position, iterasi dari FRONT hingga akhir array
			while (FRONT_position <= max - 1) {
				cout << queues_array[FRONT_position] << "	";
				FRONT_position++;
			}
		}
	}
};
int main()
{

}