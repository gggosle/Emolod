#pragma once
class Id {
private:
	int id = 0;
public:
	Id(int id) {
		this->id = id;
	}
	void setId(int id) {
		this->id = id;
	}
	int getId() {
		return this->id;
	}
};

