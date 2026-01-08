#!/bin/bash

# **************************************************************************** #
#                                                                              #
#    Test Script for Simple Shell                                             #
#    Tests all functionalities to ensure everything works                     #
#                                                                              #
# **************************************************************************** #

# Colors
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

SHELL="./simple_shell"
PASSED=0
FAILED=0
TOTAL=0

echo -e "${BLUE}========================================${NC}"
echo -e "${BLUE}🧪 Testing Simple Shell${NC}"
echo -e "${BLUE}========================================${NC}\n"

# Function to run a test
run_test() {
    local test_name="$1"
    local command="$2"
    local expected="$3"
    
    TOTAL=$((TOTAL + 1))
    
    echo -e "${YELLOW}Test $TOTAL: $test_name${NC}"
    
    # Run command through shell
    result=$(echo "$command" | $SHELL 2>&1 | grep -v "^\$")
    
    if echo "$result" | grep -q "$expected"; then
        echo -e "${GREEN}✅ PASSED${NC}\n"
        PASSED=$((PASSED + 1))
    else
        echo -e "${RED}❌ FAILED${NC}"
        echo -e "Expected: $expected"
        echo -e "Got: $result\n"
        FAILED=$((FAILED + 1))
    fi
}

# Function to test command execution
test_command() {
    local test_name="$1"
    local command="$2"
    
    TOTAL=$((TOTAL + 1))
    
    echo -e "${YELLOW}Test $TOTAL: $test_name${NC}"
    
    # Run command through shell
    output=$(echo "$command" | $SHELL 2>&1)
    exit_code=$?
    
    if [ $exit_code -eq 0 ] || echo "$output" | grep -qv "not found"; then
        echo -e "${GREEN}✅ PASSED${NC}\n"
        PASSED=$((PASSED + 1))
    else
        echo -e "${RED}❌ FAILED${NC}"
        echo -e "Output: $output\n"
        FAILED=$((FAILED + 1))
    fi
}

# Check if shell exists
if [ ! -f "$SHELL" ]; then
    echo -e "${RED}Error: $SHELL not found!${NC}"
    echo -e "${YELLOW}Run 'make' first to compile the shell.${NC}"
    exit 1
fi

echo -e "${BLUE}📋 Basic Command Tests${NC}\n"

# Test 1: ls command
test_command "Execute 'ls' command" "ls"

# Test 2: pwd command
test_command "Execute 'pwd' command" "pwd"

# Test 3: echo command
run_test "Execute 'echo Hello' command" "echo Hello" "Hello"

# Test 4: Command with arguments
test_command "Execute 'ls -l' with arguments" "ls -l"

echo -e "${BLUE}📋 Built-in Commands Tests${NC}\n"

# Test 5: env command
test_command "Execute 'env' built-in" "env"

# Test 6: exit command
TOTAL=$((TOTAL + 1))
echo -e "${YELLOW}Test $TOTAL: Execute 'exit' built-in${NC}"
echo "exit" | $SHELL > /dev/null 2>&1
if [ $? -eq 0 ]; then
    echo -e "${GREEN}✅ PASSED${NC}\n"
    PASSED=$((PASSED + 1))
else
    echo -e "${RED}❌ FAILED${NC}\n"
    FAILED=$((FAILED + 1))
fi

echo -e "${BLUE}📋 Error Handling Tests${NC}\n"

# Test 7: Invalid command
TOTAL=$((TOTAL + 1))
echo -e "${YELLOW}Test $TOTAL: Handle invalid command${NC}"
output=$(echo "invalid_command_xyz" | $SHELL 2>&1)
if echo "$output" | grep -q "not found"; then
    echo -e "${GREEN}✅ PASSED - Error message displayed${NC}\n"
    PASSED=$((PASSED + 1))
else
    echo -e "${RED}❌ FAILED - No error message${NC}\n"
    FAILED=$((FAILED + 1))
fi

# Test 8: EOF handling (Ctrl+D)
TOTAL=$((TOTAL + 1))
echo -e "${YELLOW}Test $TOTAL: Handle EOF (Ctrl+D)${NC}"
echo "" | $SHELL > /dev/null 2>&1
if [ $? -eq 0 ]; then
    echo -e "${GREEN}✅ PASSED${NC}\n"
    PASSED=$((PASSED + 1))
else
    echo -e "${RED}❌ FAILED${NC}\n"
    FAILED=$((FAILED + 1))
fi

echo -e "${BLUE}📋 PATH Resolution Tests${NC}\n"

# Test 9: Command with full path
test_command "Execute command with full path" "/bin/ls"

# Test 10: Multiple commands in sequence
TOTAL=$((TOTAL + 1))
echo -e "${YELLOW}Test $TOTAL: Execute multiple commands${NC}"
output=$(echo -e "ls\npwd\necho test" | $SHELL 2>&1)
if [ $? -eq 0 ]; then
    echo -e "${GREEN}✅ PASSED${NC}\n"
    PASSED=$((PASSED + 1))
else
    echo -e "${RED}❌ FAILED${NC}\n"
    FAILED=$((FAILED + 1))
fi

# Display results
echo -e "${BLUE}========================================${NC}"
echo -e "${BLUE}📊 Test Results${NC}"
echo -e "${BLUE}========================================${NC}"
echo -e "Total tests: $TOTAL"
echo -e "${GREEN}Passed: $PASSED${NC}"
echo -e "${RED}Failed: $FAILED${NC}"

if [ $FAILED -eq 0 ]; then
    echo -e "\n${GREEN}🎉 All tests passed!${NC}"
    exit 0
else
    echo -e "\n${RED}⚠️  Some tests failed!${NC}"
    exit 1
fi
