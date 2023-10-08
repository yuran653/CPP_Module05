/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nested.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:13:15 by jgoldste          #+#    #+#             */
/*   Updated: 2023/10/08 15:22:19 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Entity {
	private:
		int _id;

	public:
		class Position {
			public:
				Position(int x, int y) : _x(x), _y(y) {
				}
				void Print() {
					std::cout << "Position: (" << _x << ", " << _y << ")" << std::endl;
				}
			private:
				int	_x;
				int	_y;
	};

	Entity(int id) : _id(id) {
	}
};
