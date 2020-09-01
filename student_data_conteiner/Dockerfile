# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anolivei <anolivei@student.42sp.org>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/16 20:31:32 by anolivei          #+#    #+#              #
#    Updated: 2020/07/15 13:21:20 by anolivei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Baixa e usa a Imagem debian buster (OS) no Dockerhub
FROM debian:buster

# Copia a pasta srcs para a pasta root do container
COPY srcs /root/

# Cria a pasta student_data, volta para o root
# e copia a pasta student_data para student_data criada
RUN mkdir student_data
RUN cd root
COPY student_data /student_data/

# Retira as iteracoes da instalacao
# deixando a instalacao mais rapida
ARG DEBIAN_FRONTEND=noninteractive

# Faz update, upgrade e instala  tools para o Debian Buster
# Instala make, curl e build essentials
RUN apt-get update
RUN	apt-get upgrade -u
RUN	apt-get install -y make libcurl4-openssl-dev build-essential

# Liga o bash para encontrar e executar files no container
ENTRYPOINT bash /root/start.sh

# Roda o container por tempo indeterminado
CMD tail -f /dev/null
