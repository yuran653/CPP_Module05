/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_binding.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 17:06:44 by jgoldste          #+#    #+#             */
/*   Updated: 2023/10/08 17:08:06 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Shape {
public:
    virtual void draw() {
        std::cout << "Drawing a shape" << std::endl;
    }
};

class Circle : public Shape {
public:
    void draw() {
        std::cout << "Drawing a circle" << std::endl;
    }
};

int main() {
    Shape* shapePtr = new Circle();
    shapePtr->draw(); // What gets called here?
    delete shapePtr;
    return 0;
}
