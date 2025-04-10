/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:52:12 by allan             #+#    #+#             */
/*   Updated: 2025/03/31 15:36:43 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include "Contact.class.hpp"

class PhoneBook {

	public:
		PhoneBook(void);
		~PhoneBook(void);
		void add(Contact& new_contact);	
		int search(void) const;	
	
	private:	
		Contact _contact[8];
		bool _occupied[8];
		int _contact_count;
		void _print_contact_tab(void) const;
		void _print_contact(const Contact &contact) const;
		void _print_truncate(const std::string &info) const;
};

#endif