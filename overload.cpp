/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overload.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:52:20 by jgoldste          #+#    #+#             */
/*   Updated: 2023/10/03 16:31:37 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Point {
private:
	int x;
	int y;

public:
	Point(int x, int y) : x(x), y(y) {}

	// Overload the output operator
	friend std::ostream& operator<<(std::ostream& os, const Point& point) {
		os << "Point(" << point.x << ", " << point.y << ")";
		return os;
	}
};

int main() {
	Point p(3, 4);
	std::cout << "The point is: " << p << std::endl; // Using the overloaded operator
	return 0;
}
