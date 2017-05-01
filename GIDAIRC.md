# gidairc
Runtime configuration file

> Also in&nbsp;
> <a href="docs/pt_BR/GIDAIRC.md">🇧🇷</a>

## Usage

Things you can configure in gidai are:

- `useColor` - use of color (depends on your terminal compatibility)
- `useStrikethrough` - use of strikethrough font (depends on your terminal compatibility)
- `language` - language used in user interface (not working yet)

The file must be on the same path as the executable.

## Exemple

This is the default values. If gidai don't find a `.gidairc` file, or some value is not forced by this file, it will use the following values.
```
language=pt_BR
useColor=true
useStrikethrough=true
" you can use double quotes to comment, it must be on the first character of the line
" a space cannot appear before neither after de equal character
```
