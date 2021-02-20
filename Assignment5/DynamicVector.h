#pragma once


template <typename T>
class DynamicVector
{
private:
	int size;
	int capacity;
	T* elems;

public:
	DynamicVector(int cap = 10);
	DynamicVector(const DynamicVector& v);
	DynamicVector& operator=(const DynamicVector& v);
	void operator+(const T x);
	T& operator[](int pos);
	
	void append(const T x);
	void resize();

	T get(const int);

	int getSize();

	void remove(const int&);

	~DynamicVector();
};

//typedef DynamicVector Repository;

template <typename T>
DynamicVector<T>& operator+(T e, DynamicVector<T>& y) {
	// Vector + element
	y.append(e);
	return y;
}

template <typename T>
DynamicVector<T>::DynamicVector(int cap)
{
	// Init
	this->size = 0;
	this->capacity = cap;
	this->elems = new T[this->capacity];
}

template <typename T>
DynamicVector<T>::DynamicVector(const DynamicVector & v)
{
	// Vector{ vector }
	this->capacity = v.capacity;
	this->size = v.size;

	this->elems = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];
}

template <typename T>
void DynamicVector<T>::operator+(const T x) {
	// vector + elem
	this->append(x);
}

template <typename T>
DynamicVector<T>& DynamicVector<T>::operator=(const DynamicVector& v)
{
	// vector = vector
	if (this == &v)
		return *this;

	this->capacity = v.capacity;
	this->size = v.size;

	delete[] this->elems;
	this->elems = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];
	return *this;
}

template <typename T>
T& DynamicVector<T>::operator[](int pos)
{
	// vector[ int ] -- getter
	return this->elems[pos];
}

template <typename T>
void DynamicVector<T>::resize() {
	// Resize
	T* new_list = new T[2 * this->capacity];

	this->capacity *= 2;

	for (int i = 0; i < this->size; ++i) {
		new_list[i] = this->elems[i];
	}

	delete[] this->elems;
	this->elems = new_list;
}

template <typename T>
void DynamicVector<T>::remove(const int& P) {
	// Remove vector [ i ]
	int i;

	for (i = P; i < this->size - 1; ++i) {
		this->elems[i] = this->elems[i + 1];
	}

	this->size--;
}

template <typename T>
void DynamicVector<T>::append(const T x) {
	// append
	if (this->size >= this->capacity) {
		this->resize();
	}

	this->elems[this->size++] = x;
}

template <typename T>
T DynamicVector<T>::get(const int i) {
	return this->elems[i];
}

template <typename T>
int DynamicVector<T>::getSize() {
	return this->size;
}

template <typename T>
DynamicVector<T>::~DynamicVector()
{
	delete[] this->elems;
}