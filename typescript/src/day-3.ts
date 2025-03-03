import * as fs from "fs";
import * as readline from "readline";

class Stack<T> {
	public items: T[];

	constructor() {
		this.items = [];
	}

	push(element: T): void {
		this.items.push(element);
	}
	pop(): T | undefined {
		return this.items.pop();
	}
	top(): T | undefined {
		return this.items[this.items.length - 1];
	}
	isEmpty(): boolean {
		return this.items.length === 0;
	}
	size(): number {
		return this.items.length;
	}
	clear(): void {
		this.items = [];
	}
}

async function processFile(): Promise<void> {
	try {
		const filePath: string = "./input.txt";

		// Read file content asynchronously
		const fileStream = fs.createReadStream(filePath);
		const rl = readline.createInterface({ input: fileStream, crlfDelay: Infinity });

		let fullText = "";

		// Read the entire file line by line
		for await (const line of rl) {
			fullText += line;
		}

		const result = process_string(fullText);
		console.log("Final sum:", result);
	} catch (error) {
		console.error("Error:", error);
	}
}

function process_string(s: string): number {
	const stack = new Stack<string>();
	let cur_no = "";
	let num1 = "";
	let num2 = "";
	let sum = 0;
	let in_mul = false;
	let found_comma = false;

	for (let i = 0; i < s.length; i++) {
		if (s.slice(i, i + 4) === "mul(") {
			in_mul = true;
			stack.push("mul(");
			i += 3;
			num1 = "";
			num2 = "";
			found_comma = false;
		}

		// Capture valid numbers inside a mul() block
		else if (!isNaN(parseInt(s[i])) && in_mul) {
			if (!found_comma) {
				num1 += s[i]; // First number
			} else {
				num2 += s[i]; // Second number
			}
		}

		// Detect comma inside a valid "mul(x,y)"
		else if (s[i] === ',' && in_mul) {
			if (num1 !== "") {
				found_comma = true;
			} else {
				// Invalid: If comma appears before any number
				in_mul = false;
				stack.clear();
			}
		}

		else if (s[i] === ')' && in_mul) {
			if (num1 !== "" && num2 !== "" && found_comma) {
				const product = parseInt(num1) * parseInt(num2);
				sum += product;
			}
			// Reset state
			in_mul = false;
			stack.clear();
		}

		// If any invalid character appears inside `mul(...)`, reset
		else if (in_mul && ![" ", ",", ")", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"].includes(s[i])) {
			in_mul = false;
			stack.clear();
		}
	}

	return sum;
}

processFile();

