#lang racket
(require "lpp.rkt")
(require rackunit)




(check-equal? (to-string-arbol '(a (b (c) (d)) (e (f)) (g (h) (i)))) "abcdefghi")

