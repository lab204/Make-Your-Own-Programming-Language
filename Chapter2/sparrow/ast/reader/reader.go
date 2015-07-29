package reader

import (
	"errors"
	"fmt"
)

type Reader interface {
	next() *string
	peek() *string
}

func next() *string {
	return new(string)
}

func peek() *string {
	return new(string)
}

type TokenReader struct {
	tokens   []string
	position int
}

func tokenize(str string) []string {
	results = make([]string)

	return results
}

func read_form(tr TokenReader) (bool, error) {

}

func Read(str string) (bool, error) {
	tokens = tokenize(str)

	if len(tokens) == 0 {
		return false, errors.New("error")
	}
	read_form(&TokenReader{tokens: tokens, position: 0})
}
