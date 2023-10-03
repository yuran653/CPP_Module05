/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   friend.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:02:38 by jgoldste          #+#    #+#             */
/*   Updated: 2023/10/03 16:29:10 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class MyClass {
	private:
		int _privateMember;

	public:
 		MyClass(int val) : _privateMember(val) {}

	// Public member function to access privateMember
	int getPrivateMember() const;

	friend void friendFunction(MyClass&);
	
};

int MyClass::getPrivateMember() const {
		return _privateMember;
}

// Definition of the friend function
void friendFunction(MyClass& obj) {
	// Accessing the private member of MyClass
	obj._privateMember = 42;
}

int main() {
	MyClass myObject(10);

	std::cout << "Initial value of privateMember: " << myObject.getPrivateMember() << std::endl;

	// Call the friend function to modify privateMember
	friendFunction(myObject);

	std::cout << "Modified value of privateMember: " << myObject.getPrivateMember() << std::endl;

	return 0;
}
