package types

import (
	"errors"
	"fmt"
	"reflect"
	"strings"
)

type SrwType interface {
}

type SrwError struct {
	Obj SrwType
}

type Symbol struct {
	Val string
}

func (e SrwError) Error() string {
	return fmt.Sprintf("%#v", e.Obj)
}

type EnvType interface {
	Find(key Symbol) EnvType
	Set(key Symbol, value SrwType) SrwType
	Get(key Symbol) (SrwType, error)
}
