# Pharo syntax

## Read/Execute order
### Read order
* (Msg) > Unary > Binary > Keywords
* Same level => from left to right
	<small> <u>example :</u> </small>
	<code>1000 factorial class name </code> = <code>(((1000 factorial) class) name)</code>

### Execute order
* (...) > unary > binary > keywords

## Cascade sending
```smalltalk
Transcript cr.
Transcript show: 1.
Transcript show: 2
```

is equivalent to :

```smalltalk
Transcript
	cr;
	show: 1;
	show: 2;
```
## Local variable
```smalltalk
methodName
  | var1 var2 ... |
  "...program..."
```

## Blocks [...]

* [ <small>...expression...</small> ] is a lambda expression

	<small> <u>example :</u> </small>
	```smalltalk
	[:x | x+1 ] value: 7 "return 8"
	```

## ArrayList
<code> varName := OrderedCollection new.</code>

## Condition (if..then..else)
```smalltalk
condition ifTrue: value_if_true ifFalse value_if_false
```

## Loops
```smalltalk
4 timesRepeat: [ self doSomething ]
0 to: 100 do: [:i |...]
0 to: 100 by: 3 do: [:i |...]
aCollection do: [:each |...]
```