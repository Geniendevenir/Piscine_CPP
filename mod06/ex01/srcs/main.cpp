/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:42:25 by adebert           #+#    #+#             */
/*   Updated: 2025/05/29 13:10:02 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void) {
	//Check Serializer can't be initialized by the user;
	//Serializer a; //Creates an Error
	//Serializer *a = new Serializer; // Creates an Error
	Data* pre_data = new Data; 
	pre_data->name = "Henry";
	pre_data->age = 47;
	try {

		uintptr_t s_data = Serializer::serialize(pre_data);
		std::cout << "Serialized Data = " << s_data << "\n" << std::endl;
		
		Data* post_data = Serializer::deserialize(s_data);
		
		std::cout << "Data Address (Before Serialization): " << pre_data << std::endl;
		std::cout << "Data Address (After Deserialization): " << post_data << std::endl;

		if (pre_data == post_data) {
			std::cout << "Success: Data Addresses are the same" << std::endl;
		} else
			throw std::runtime_error("Error: Data Addresses are different");
		
		std::cout << std::endl;

		std::cout << "Data Content (Before Serialization):" << std::endl;
		std::cout << *pre_data << std::endl;
		std::cout << "Data Content (After Serialization):" << std::endl;
		std::cout << *post_data << std::endl;
			
		delete pre_data;
		
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		delete pre_data;
		return 1;
	}

	return (0);
}
