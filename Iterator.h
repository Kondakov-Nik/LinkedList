#pragma once

// @author Kondakov N

template<class T>

// абстрактный класс итератор

class Iterator {
public:
	// оператор перехода на следующий элемент
	virtual Iterator<T>& operator++() = 0;

	// оператор получения данных их элемента
	virtual T& operator*() const = 0;

	// операторы сравнения текущего итератора с другим
	virtual bool operator==(const Iterator<T>& other) const = 0; // если указывают тот же элемент
	virtual bool operator!=(const Iterator<T>& other) const = 0; // если НЕ указывают тот же элемент
};