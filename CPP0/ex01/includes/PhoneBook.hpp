/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 03:01:21 by llebioda          #+#    #+#             */
/*   Updated: 2025/01/24 05:21:36 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP
# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int index;

	public:
		PhoneBook();
		PhoneBook(const PhoneBook& other);
		PhoneBook &operator=(const PhoneBook& other);
		~PhoneBook();

		void addContact(Contact newContact);
		bool searchContacts();
		void displayContact(int idx);
};

#endif