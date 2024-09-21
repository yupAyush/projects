#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct items
{
    char item[20];
    float price;
    int qty;
};
struct orders
{
    char customer[50];
    char date[50];
    int numberOfItems;
    struct items itm[50];
    
    
};
void genrateBillHeader(char name[50],char date[30]){
    printf("\n\n");
    printf("\t  ADV .Restaurant");
    printf("\t\n---------------------------------------");
    printf("\nDate.%s",date);
    printf("\nInvoice To: %s",name);
    printf("\n");
    printf("---------------------------------------\n");
    printf("Items\t\t");
    printf("Qty\t\t");
    printf("Total\n\n");
    printf("\n---------------------------------------");
    printf("\n\n");



}

void genrateBillBody( char item[30], int qty,float price){
        printf("%s\t\t",item); 
        printf("%d\t\t",qty); 
        printf("%.2f\t\t",qty * price); 
        printf("\n");
}


void generateBillFooter(float total){
    printf("\n");
    float dis = 0.1*total;
    float netTotal=total-dis;
    float cgst=0.09*netTotal,grandTotal=netTotal + 2*cgst;//netTotal + cgst + sgst
    printf("---------------------------------------\n");
    printf("Sub Total\t\t\t%.2f",total);
    printf("\nDiscount @10%s\t\t\t%.2f","%",dis);
    printf("\n\t\t\t\t-------");
    printf("\nNet Total\t\t\t%.2f",netTotal);
    printf("\nCGST @9%s\t\t\t%.2f","%",cgst);
    printf("\nSGST @9%s\t\t\t%.2f","%",cgst);
    printf("\n---------------------------------------");
    printf("\nGrand Total\t\t\t%.2f",grandTotal);
    printf("\n---------------------------------------\n");
}

int main(){
    struct orders ord;
    struct orders order;
    int opt,n,invoicef;
    char savebill ='y';
    FILE *fp;
    char name[50];
    
    float t ,tot;
    

    printf("=============ADV.RESTAURANT.=============");
    printf("\n\nPlease select your prefered options");
    printf("\n\n1.Genrate Invoice");
    printf("\n2Show all Invoices");
    printf("\n3.Search Invoice");
    printf("\n4.Exit");
    printf("\n\nYour choice:\t");
    scanf("%d",&opt);
    fgetc(stdin);
   
    switch (opt)
    {
      case 1:
      system("clear");
      printf("\n Please enter the name of the customer:\t");
      fgets(ord.customer,50,stdin);
      ord.customer[strlen(ord.customer)-1]=0;
      strcpy(ord.date,__DATE__);
      printf("Please enter no of items:\t");
      scanf("%d",&n);
      ord.numberOfItems=n;
      for (int i = 0; i < n; i++)
      {
        fgetc(stdin);
        printf("\n\n");
        printf("Please enter the item %d:\t",i+1);
        fgets(ord.itm[i].item,20,stdin);
        ord.itm[i].item[strlen(ord.itm[i].item)-1]=0;
        printf("Please enter the quantity:\t");
        scanf("%d",&ord.itm[i].qty);
        printf("Please enter the unit price :\t");
        scanf("%f",&ord.itm[i].price);
        t +=(ord.itm[i].qty * ord.itm[i].price);
        
      }
      genrateBillHeader(ord.customer,ord.date);
      for (int i = 0; i < ord.numberOfItems; i++)
      {
        genrateBillBody(ord.itm[i].item,ord.itm[i].qty,ord.itm[i].price);
        
      }
      generateBillFooter(t);
      printf("\nDo u want to save this invoice [y/n] :\t");
      scanf("%S",&savebill);
      if(savebill=='y'){
        fp = fopen("RestaurantBill.txt","a+");
        fwrite(&ord,sizeof(struct orders),1,fp);
        if(fwrite!=0){
          printf("\nSuccessfully saved");
        }
        else{
          printf("\nError saving....");
        }
        fclose(fp);
        

      }
      break;
      case 2:
       
       system("clear");
       fp=fopen("RestaurantBill.txt","r");
       printf("\n  *****Your Previous Invoices*****\n");
       while (fread(&order,sizeof(struct orders),1,fp))
        {
        
        genrateBillHeader(order.customer,order.date);
        for (int i = 0; i <order.numberOfItems; i++)
        {
          genrateBillBody(order.itm[i].item,order.itm[i].qty,order.itm[i].price);
          tot+=order.itm[i].qty * order.itm[i].price;
        }
        generateBillFooter(tot);
        
        
       }
       fclose(fp);
      break;
      case 3:
       printf("\n Enter the name of the customer:\t");
       
       fgets(name,50,stdin);
       name[strlen(name)-1]=0;
       system("clear");
       fp=fopen("RestaurantBill.txt","r");
       printf("\t*****Invoice of %s*****",name);
       while (fread(&order,sizeof(struct orders),1,fp))
       {
         float total;
         
         if (strcpy(order.customer,name))
         {
          genrateBillHeader(order.customer,order.date);
          for(int i=0;i<order.numberOfItems;i++){
                genrateBillBody(order.itm[i].item,order.itm[i].qty,order.itm[i].price);
                total+=order.itm[i].qty * order.itm[i].price;

           }
         generateBillFooter(total);
         invoicef=1;
         }
         if (invoicef!=1)
         {
           printf("\nSorry invoice doesnt exist:\t");
         }
         
         }
       fclose(fp);
      break;
      case 4:
       exit(0);
       break;

  
    }


    printf("\n\n");
    return 0;
}