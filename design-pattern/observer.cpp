#include <iostream>
#include <vector>


using namespace std;


class Observer {
public:

	virtual void update(float temp, float humidity, float pressure) = 0 {};

};

class Subject {
public:

	virtual void registerObserver(Observer* o) = 0 {};
	virtual void removeObserver(Observer* o) = 0 {};
	virtual void notifyObservers() = 0 {};

};


class DisplayElement {
public:
	virtual void display() = 0 {};
};

class WeatherData : public Subject {

private:
	// ʹ�� vector ����¼�۲���
	vector<Observer*> observers;

	float temperature;
	float humidity;
	float pressure;

public:
	WeatherData() {

	}


	void registerObserver(Observer* o) {
		observers.push_back(o);
	}

	void removeObserver(Observer* o) {

		if (observers.empty()) {
			return;
		}

		vector<Observer*>::const_iterator it;

		for (it = observers.begin(); it != observers.end();) {
			if (*it == o) {
				it = observers.erase(it);
			} else {
				++it;
			}
		}
	}

	/// <summary>
	/// ֪ͨ�����۲���
	/// </summary>
	void notifyObservers() {
		if (observers.empty()) {
			return;
		}

		// ֪ͨ�����۲���
		for (auto it = observers.begin(); it != observers.end(); ++it) {
			(*it)->update(temperature, humidity, pressure);
		}
	}

	void messurementsChanged() {
		notifyObservers();
	}

	void setMeasurements(float temperature, float humidity, float pressure) {
		this->temperature = temperature;
		this->humidity = humidity;
		this->pressure = pressure;

		messurementsChanged();
	}

};

class CurrentConditionsDisplay : public Observer, public DisplayElement {
private:
	float temperature;
	float humidity;

	Subject* weatherData;

public:

	/// <summary>
	/// �ڹ��췽���н���ע��
	/// </summary>
	/// <param name="weatherData"></param>
	CurrentConditionsDisplay(Subject* weatherData) {
		this->weatherData = weatherData;
		weatherData->registerObserver(this);
	}

	void update(float temperature, float humidity, float pressure) {
		this->temperature = temperature;
		this->humidity = humidity;

		display();
	}

	void display() {
		cout << "Current conditions: " << temperature << "F degrees and " << humidity << "% humidity";
	}
};

int main() {

	WeatherData weatherData;

	CurrentConditionsDisplay currentDisplay(&weatherData);

	weatherData.setMeasurements(80, 65, 30.4f);

	return 0;
}