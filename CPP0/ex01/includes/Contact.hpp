/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 03:01:21 by llebioda          #+#    #+#             */
/*   Updated: 2025/01/24 03:58:25 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;

		std::string truncateString(std::string str);

	public:
		Contact();
		Contact(const Contact& other);
		Contact &operator=(const Contact& other);
		~Contact();

		void addContact(std::string firstName, std::string lastName,
			std::string nickname, std::string phoneNumber, std::string darkestSecret);
		void displayShortInfo(int index);
		void displayFullInfo();
		bool isEmpty();
};

#endif