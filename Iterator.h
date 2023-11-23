#pragma once

// @author Kondakov N

template<class T>

// ����������� ����� ��������

class Iterator {
public:
	// �������� �������� �� ��������� �������
	virtual Iterator<T>& operator++() = 0;

	// �������� ��������� ������ �� ��������
	virtual T& operator*() const = 0;

	// ��������� ��������� �������� ��������� � ������
	virtual bool operator==(const Iterator<T>& other) const = 0; // ���� ��������� ��� �� �������
	virtual bool operator!=(const Iterator<T>& other) const = 0; // ���� �� ��������� ��� �� �������
};