#! /usr/bin/expect -f

set TEST_CASE [lindex $argv 0]

spawn "./${TEST_CASE}.out"
expect { 
	"__VERIFIER_error was executed\r" {
	} timeout {
		send_user "timeout\n"
		send "\x03"
	} eof {
		send_user "unexpected end\n"
		exit 1
	}
}
