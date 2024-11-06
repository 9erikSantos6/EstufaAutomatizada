# Estufa Automatizada com Arduino

Este projeto implementa uma estufa automatizada utilizando placas Arduino, projetada para monitoramento e controle automático de irrigação, temperatura e umidade. A estufa é equipada com sensores de umidade do solo, sensores de temperatura e umidade do ar, além de um sistema de teto retrátil acionado por motores de passo para controle de luz e ventilação.

## Funcionalidades

- **Sistema de Irrigação Automática:** Controlado por um sensor de umidade do solo que aciona a irrigação conforme a necessidade de água das plantas.
- **Monitoramento de Temperatura e Umidade:** Sensores de temperatura e umidade do ar garantem o controle climático interno.
- **Teto Retrátil Automatizado:** Acionado por motores de passo, o teto retrátil permite o controle de exposição à luz e ventilação, melhorando as condições internas de acordo com os dados dos sensores.
  
## Estrutura do Projeto

EstufaAutomatizada/
┣ include/
┃ ┣ MotorPassos.h               # Cabeçalho para controle de motores de passo
┃ ┣ SensorHumidadeSolo.h         # Cabeçalho para sensor de umidade do solo
┃ ┣ SensorTemperatura.h          # Cabeçalho para sensor de temperatura e umidade do ar
┃ ┗ README                       # Informações de bibliotecas adicionais
┣ lib/
┃ ┗ README                       # Pastas para bibliotecas adicionais (vazias por enquanto)
┣ src/
┃ ┣ modules/
┃ ┃ ┣ MotorPassos/
┃ ┃ ┃ ┗ MotorPassos.cpp          # Implementação do controle do motor de passo
┃ ┃ ┣ SensorHumidadeSolo/
┃ ┃ ┃ ┗ SensorHumidadeSolo.cpp   # Implementação do sensor de umidade do solo
┃ ┃ ┗ SensorTemperatura/
┃ ┃   ┗ SensorTemperatura.cpp    # Implementação do sensor de temperatura e umidade
┃ ┗ main.cpp                     # Arquivo principal do projeto
┣ test/
┃ ┗ README                       # Pastas para testes
┣ .editorconfig                  # Configuração de editor
┣ .gitignore                     # Arquivos e pastas a serem ignorados pelo Git
┗ platformio.ini                 # Configurações do PlatformIO

## Requisitos

- **Hardware:**
  - Placa Arduino (ou outra plataforma compatível com PlatformIO)
  - Sensor de umidade do solo
  - Sensor de temperatura e umidade do ar
  - Motor de passo e driver de controle para o teto retrátil
  - Bomba de água para irrigação
  
- **Software:**
  - [PlatformIO](https://platformio.org/) como ambiente de desenvolvimento

## Instalação

1. **Clone este repositório:**
   ```bash
   git clone https://github.com/usuario/EstufaAutomatizada.git
   ```

2. **Entre no diretório do projeto:**
   ```bash
   cd EstufaAutomatizada
   ```

3. **Abra o projeto no PlatformIO:**
   - Inicie o PlatformIO e abra o diretório do projeto.

4. **Configure a plataforma:**
   - O arquivo `platformio.ini` já contém as configurações para o ambiente de desenvolvimento e compilação.
   
5. **Conecte o Arduino** e faça o upload do código:
   ```bash
   pio run --target upload
   ```

## Como Usar

1. **Inicie o sistema:** Após o upload do código, o Arduino monitorará os sensores automaticamente.
2. **Controle de Irrigação:** O sistema de irrigação será acionado quando o sensor de umidade do solo indicar níveis abaixo do desejado.
3. **Controle Climático:** O teto retrátil, acionado pelos motores de passo, abre ou fecha conforme os níveis de temperatura e umidade capturados pelos sensores.

## Estrutura do Código

- **`main.cpp`:** Arquivo principal que inicializa os sensores, o motor e define a lógica de controle.
- **Módulos:** Cada módulo (`MotorPassos`, `SensorHumidadeSolo`, `SensorTemperatura`) possui um arquivo `.cpp` de implementação e um cabeçalho `.h`, mantendo a organização do projeto e facilitando futuras expansões.

## Contribuição

1. Faça um fork deste repositório.
2. Crie uma branch para sua nova funcionalidade (`git checkout -b feature/nova-funcionalidade`).
3. Commit suas alterações (`git commit -m 'Adiciona nova funcionalidade'`).
4. Faça o push para a branch (`git push origin feature/nova-funcionalidade`).
5. Abra um Pull Request.

## Licença

Este projeto está licenciado sob a [MIT License](LICENSE).

## Contato

Para dúvidas ou sugestões, entre em contato com [9xerikx6@gmail.com](mailto:9xerikx6@gmail.com).