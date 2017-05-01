# gidairc
Arquivo de configuração em tempo de execução

> Also in&nbsp;
> <a href="../../GIDAIRC.md">🇧🇷</a>

## Uso

Coisas que você pode configurar no gidai são:

- `useColor` - uso de cor (depende da compatibilidade do seu terminal)
- `useStrikethrough` - uso de fonte tachada (depende da compatibilidade do seu terminal)
- `language` - idioma utilizado pela interface com o usuário (ainda não está funcionando)

Este arquivo deve estar no mesmo diretório que o executável.

## Exemplo

Estes são os valores padrão. Se o gidai não encontrar um arquivo `.gidairc`, ou se algum valor não for configurado por este arquivo, irá utilizar os seguintes valores:
```
language=pt_BR
useColor=true
useStrikethrough=true
" você pode usar aspas duplas para comentar, elas devem ser o primeiro caractere da linha
" não deve ser colocado um espaço antes nem depois do caractere de igual
```
