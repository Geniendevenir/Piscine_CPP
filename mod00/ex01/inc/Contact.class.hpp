/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:52:12 by allan             #+#    #+#             */
/*   Updated: 2025/03/31 02:20:57 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

#include <string>
#include <iostream>

#define PHONE 1
#define FIRST_NAME 2 
#define LAST_NAME 3 
#define NICKNAME 4
#define SECRET 5 

class Contact {

	public:
		Contact(void);
		~Contact(void);
		int create(void);
	
		std::string getInfo(int info) const;
		
	private:	
		std::string	_phone_number;
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _darkest_secret;	
};

#endif