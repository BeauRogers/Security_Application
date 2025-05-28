import requests
from requests.auth import HTTPBasicAuth
import sys

# --- Replace these with your actual values ---
api_key = "19885dcdd056ed5419c7a070db2e88bc906e84e8dbbda6b7"
api_token = "3c260ab44b0adce150be28f8236fa7c7487abba602d7c32b"
subdomain = "api.in.exotel.com"  # or whatever your actual subdomain is
sid = "your_sid"


def connect_call(desiredNumber):
    # Endpoint URL
    url = f"https://{subdomain}/v1/Accounts/{sid}/Calls/connect"

    # Request payload (adjust based on API docs)
    payload = {
        "From": "your_verified_number",     # e.g., "+14155552671"
        "To": desiredNumber,         # e.g., "+918123456789"
        "CallerId": "your_caller_id",       # e.g., Exotel virtual number
        "CallType": "trans"                 # or "promo", depending on API
    }

    # Send POST request
    response = requests.post(url, data=payload, auth=HTTPBasicAuth(api_key, api_token))

    # Print the response
    print("Status Code:", response.status_code)
    print("Response Body:", response.text)


# Replace with your Exotel credentials
SID = "your_exotel_sid"
TOKEN = "your_exotel_token"

# Base URL
BASE_URL = f"https://api.exotel.com/v1/Accounts/{SID}"

# Example 1: GET account details (or any other endpoint)
def get_account_info():
    url = f"{BASE_URL}/Calls.json"  # or any other GET endpoint
    response = requests.get(url, auth=HTTPBasicAuth(SID, TOKEN))

    print("GET Response Status Code:", response.status_code)
    print("GET Response Body:", response.text)

# Example 2: POST to make a call
def make_call():
    url = f"{BASE_URL}/Calls/connect.json"
    payload = {
        "From": "+919999999999",     # Replace with a verified number
        "To": "+918888888888",       # Replace with a destination number
        "CallerId": "+911234567890", # Verified caller ID from Exotel
        "CallType": "trans"
    }

    response = requests.post(url, data=payload, auth=HTTPBasicAuth(SID, TOKEN))

    print("POST Response Status Code:", response.status_code)
    print("POST Response Body:", response.text)

# Run the functions
if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Error: Phone number required")
        sys.exit(1)
    connect_call(sys.argv[1])
