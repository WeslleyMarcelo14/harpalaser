# Harpa Laser

Este projeto consiste em um instrumento de cordas sem o uso de interface MIDI, adaptado para ser mais acessível e viável para projetos educacionais.

## Sobre o Projeto

O projeto foi inspirado e adaptado a partir do [Arduino Laser Harp](https://www.instructables.com/Arduino-Laser-Harp-1/), visando reduzir o custo, especialmente considerando sua aplicação em uma feira de ensino médio no Brasil. Uma interface MIDI, apesar de ideal, foi considerada inviável devido ao alto custo para um projeto temporário.

Para o desenvolvimento, foi utilizado um molde personalizado para encaixar os componentes, criado a partir de um arquivo **DWG**.

Este projeto oferece **duas opções de configuração**:
- **Sem MIDI**: Ideal para projetos mais simples e acessíveis.
- **Com MIDI**: Para maior integração com softwares musicais. Utilizou-se o software [LMMS](https://lmms.io/), uma ferramenta gratuita e open-source de produção musical.

## Materiais Utilizados

- Arduino Leonardo
- Módulo Laser KY-0008 (12 módulos)
- LDR 5mm (12 sensores)
- Resistores de 10kΩ (12 resistores)
- Protoboard ou shield (1 unidade)
- Jumpers
- Cabo micro USB (1 para o Arduino Leonardo e outro opcional para alimentação dos módulos KY-0008)

**Nota**: A quantidade de 12 sensores e módulos foi utilizada para criar uma escala musical completa.

## Teclas e Software

As teclas do projeto foram adaptadas para funcionar com o [Virtual Piano](https://virtualpiano.net/), permitindo tocar diretamente nesse software. No entanto, o sistema pode ser facilmente adaptado para outros programas de música ou simulação de teclado.

## Considerações

Os resistores são usados para ajustar a sensibilidade do sistema em função da luz ambiente. Dependendo do local onde o instrumento será utilizado, pode ser necessário ajustar os valores dos resistores.

## Licença

Este projeto está sob a licença MIT.
