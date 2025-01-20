## LINK DO VÍDEO:  https://youtube.com/shorts/oWUvF5FMhGQ


# Controle de LED RGB e Buzzer com Raspberry Pi Pico

Este programa permite controlar os LEDs RGB e um buzzer conectados à Raspberry Pi Pico através de comandos enviados via comunicação serial (UART).  

## Funcionalidades
- Acender LEDs individuais (vermelho, azul, verde).
- Acender todos os LEDs ao mesmo tempo.
- Desligar todos os LEDs.
- Acionar o buzzer por 2 segundos.

## Pré-requisitos
- Raspberry Pi Pico configurada com o SDK do Pico.
- Conexão dos pinos da Pico aos LEDs e ao buzzer:
  - **LED Verde**: GPIO 11.
  - **LED Azul**: GPIO 12.
  - **LED Vermelho**: GPIO 13.
  - **Buzzer**: GPIO 21.
- Ferramenta para comunicação serial 

## Comandos Disponíveis
Digite os seguintes comandos na interface de comunicação serial:

| Comando    | Ação                                      |
|------------|-------------------------------------------|
| `green`    | Acende o LED verde.                      |
| `blue`     | Acende o LED azul.                       |
| `red`      | Acende o LED vermelho.                   |
| `white`    | Acende todos os LEDs (vermelho, azul, verde). |
| `off`      | Desliga todos os LEDs.                   |
| `buzzer`   | Aciona o buzzer por 2 segundos.          |

## Como Usar
1. Compile o programa e grave-o na Raspberry Pi Pico.
2. Conecte a Pico ao computador via USB.
3. Abra um monitor serial configurado com:
   - **Porta**: a COM atribuída à Pico.
   - **Baudrate**: 115200.
   - **Final de Linha**: Somente `\n`.
4. Envie os comandos listados acima para controlar os LEDs e o buzzer.

## Solução de Problemas
- **Comando inválido exibido**: Certifique-se de que o comando está digitado corretamente.
- **LEDs ou buzzer não respondem**: Verifique as conexões dos GPIOs e o monitor serial.
- **Aspas nos comandos**: O programa remove automaticamente aspas enviadas por alguns terminais.


