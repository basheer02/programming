import pandas as pd

df = pd.read_csv('Test_Data.csv')

org_name = df.filter(['Organization'])
org_desc = df.filter(['Org_Desc'])
org_size = df.filter(['Org_Size'])
org_spc = df.filter(['Org_Specialities'])
org_ind = df.filter(['Org_Industry'])

org_details = (
    f"Organization Name: {org_name}\n"
    f"Description: {org_desc}\n"
    f"Size of Organization: {org_size}\n"
    f"Focus Areas: {org_spc}\n"
    f"Industry: {org_ind}"
)

df['Org_Details'] = org_details

cont_prs = df.filter(['Contact_Person'])
cont_title = df.filter(['Title'])
cont_sum = df.filter(['ContactSummary'])

cont_det = (
    f"Contact Name: {cont_prs}\n"
    f"Title: {cont_title}\n"
    f"Contact Summary: {cont_sum}\n"
)

df['Contact_Details'] = cont_det

print(df['Org_Details'])
print(df['Contact_Details'])

