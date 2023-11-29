/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichiro <ichiro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:57:56 by ichiro            #+#    #+#             */
/*   Updated: 2023/11/28 19:27:03 by ichiro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define BOLD_TEXT "\033[1m"
#define RESET "\033[0m"

#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

#define HEADER	"---------------------------------------------\n"\
				"|     Index|First Name| Last Name|  Nickname|\n"\
				"---------------------------------------------"

#define WELCOME	"Welcome, please enter one of the following commands:\n"\
				"ADD, SEARCH or EXIT\n"

#define MAX_CONTACTS 8
