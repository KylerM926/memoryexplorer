#include <iostream>

using namespace std;

void increase_temp(int* temp, int amount){
	if (temp != nullptr){
		*temp += amount;
	}
}

void display_temp(const int* temp){
	if(temp != nullptr){
		cout << "Current Temperature: " << *temp << " C\n";
	} else {
		cout << "No temperature sensor available!\n";
	}
}

int main()
{
	cout << "MEMORY EXPLORER\n";
	cout << "---------------\n\n";

	int cpuTemp = 62;
	int gpuTemp = 55; // Celsius
	double ramUsage = 7.5; // GB
	char systemStatus = 'N'; //N = Normal

	cout << "PART 1: HARDWARE MEMORY ADRESSES\n";
	cout << "--------------------------------\n";

	cout << "CPU Temp: " << cpuTemp << " C\n";
	cout << "CPU Address: " << &cpuTemp << endl;
	cout << "CPU Size: " << sizeof(cpuTemp) << " bytes\n\n";

	cout << "GPU Temp: " << gpuTemp << " C\n";
        cout << "GPU Address: " << &gpuTemp << endl;
        cout << "GPU Size: " << sizeof(gpuTemp) << " bytes\n\n";

	cout << "RAM Usage: " << ramUsage << " GB\n";
        cout << "RAM Address: " << &ramUsage << endl;
        cout << "RAM Size: " << sizeof(ramUsage) << " bytes\n\n";

        cout << "System Status: " << systemStatus << endl;
        cout << "System Address: " << static_cast<const void*>(&systemStatus) << endl;
        cout << "Status Size: " << sizeof(systemStatus) << " bytes\n\n";

        cout << "PART 2: HARDWARE POINTERS\n";
        cout << "-------------------------\n";

        int* cpuPtr = &cpuTemp;
        double* ramPtr = &ramUsage;

        cout << "CPU Temp: " << cpuTemp << endl;
        cout << "CPU Address: " << &cpuTemp << endl;
        cout << "Pointer Stores: " << cpuPtr << endl;
        cout << "Pointer Address: " << &cpuPtr << "\n\n";

        cout << "RAM Usage: " << ramUsage << endl;
        cout << "RAM Address: " << &ramUsage << endl;
        cout << "Pointer Stores: " << ramPtr << endl;
        cout << "Pointer Address: " << &ramPtr << endl << endl;

	cout << "PART 3: DEREFERENCING POINTERS\n";
	cout << "------------------------------\n";

	cout << "CPU Temp: " << cpuTemp << endl;
	cout << "CPU Pointer Address: " << cpuPtr << endl;
	cout << "CPU Dereferenced Value: " << *cpuPtr << endl << endl;

	cout << "RAM Usage: " << ramUsage << endl;
	cout << "RAM Dereferenced Value: " << *ramPtr << endl;

	cout << "\nPART 4: UPDATING HARDWARE READINGS\n";
	cout << "----------------------------------\n";

	cout << "Original CPU Temp: " << cpuTemp << endl;

	*cpuPtr = 78;

	cout << "Updated CPU Temp: " << cpuTemp << endl;
	cout << "Value through the poointer: " << *cpuPtr << endl;

	*ramPtr += 1.5;

	cout << "\nUpdated RAM Usage: " << ramUsage << endl << endl;

	cout << "PART 5: SENSOR AVAILABILITY (nullptr)\n";

	int* sensorPtr = nullptr;

	if (sensorPtr == nullptr){
		cout << "No temp sensor selected\n";
	}

	sensorPtr = &cpuTemp;

	if (sensorPtr != nullptr){
		cout << "CPU Sensor Connected.\nCurrent reading: " << *sensorPtr << endl;
	}

	cout << "\nPART 6: SWITCHING SENSORS\n";
	cout << "-------------------------\n";

	cout << "Active sensor: CPU, Reading: " << *sensorPtr << endl;

	//actual switching part
	sensorPtr = &gpuTemp;

	cout << "Active sensor: GPU, Reading: " << *sensorPtr << endl;

	*sensorPtr = 65;

	cout << "Updated GPU temp: " << gpuTemp << endl;
	cout << "CPU temp: " << cpuTemp << endl;

	cout << "\nPART 7: POINTERS VS REFERENCES\n";
	cout << "------------------------------\n";

	// create reference to the cpu temp 
	int& cpuRef = cpuTemp;

	// create a Ptr to the cpu temp
	int* currentPtr = &cpuTemp;

	cout << "CPU Temp: " << cpuTemp << endl;
	cout << "Reference Value: " << cpuRef << endl;
	cout << "Pointer Value: " << *currentPtr << endl;

	cpuRef = 82;

	cout << "After increasing through reference, CPU Temp: " << cpuTemp << endl;

	*currentPtr = 85;

	cout << "After increasing through pointer, CPU Temp: " << cpuTemp << endl;

	cout << "\nPART 8: POINTER FUNCTION PARAMATERS\n";
	cout << "------------------------------------\n";

	cout << "Before CPU update: ";
	display_temp(&cpuTemp);

	increase_temp(&cpuTemp, 5);

	cout << "After CPU update: ";
	display_temp(&cpuTemp);

	//simulate gpu rising by 10deg
	increase_temp(&gpuTemp, 10);
        cout << "After CGU update: ";
        display_temp(&gpuTemp);

	//demo a null argument
        cout << "Unavailable sensor: ";
        display_temp(nullptr);

        cout << "\nPART 9: TEMPERATURE HISTORY\n";

        int temperatures[5] = {62, 65, 68, 72, 75};

	// pointer to first element
        int* tempHPtr = temperatures;

        cout << "Temperature readings: \n";

        for (int i = 0; i < 5; i++){
		cout << "Reading " << i + 1 << ": " << temperatures[i] << endl;
        }

        for (int i = 0; i < 5; i++){
                cout << "Reading " << i + 1 << "Address: " << &temperatures[i] << endl;
        }

        cout << "\nPointer Arithmetic\n";

        cout << "First Reading: " << tempHPtr << endl;
	cout << "Second Reading: " << *(tempHPtr + 1) << endl;
	cout << "Third Reading: " << *(tempHPtr + 2) << endl;


	return 0;
}
