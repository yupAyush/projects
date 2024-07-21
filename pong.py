import pygame,sys,random

bx=7*random.choice((1,-1))
by=7*random.choice((1,-1))
def ballan():
   
   global bx,by
   ball.x +=bx
   ball.y +=by      
   if ball.top <= 0 or ball.bottom>=screen_height:
      by*=-1
   if ball.left<=0 or ball.right>=screen_width:
      ballr()

   if ball.colliderect(player) or ball.colliderect(opps):
      bx*=-1 


def ballr():
   global bx,by
   ball.center=(screen_width/2,screen_height/2)
   by*=random.choice((1,-1))
   bx*=random.choice((1,-1))
   

pygame.init()
clock=pygame.time.Clock()
screen_width= 760
screen_height= 660
screen= pygame.display.set_mode((screen_width,screen_height))
pygame.display.set_caption('pong')

bg=pygame.Color('grey12')
lg=(200,200,200)



ball=pygame.Rect(screen_width/2-15,screen_height/2-15,30,30)
player=pygame.Rect(screen_width-20,screen_height/2-70,10,140)
opps =pygame.Rect(10,screen_height/2-70,10,140)
ps=0
os=7

while True:
   for event in pygame.event.get():
       if event.type==pygame.QUIT:
          pygame.quit()
          sys.exit()
       if event.type==pygame.KEYDOWN:
          if event.key==pygame.K_DOWN:
             ps+=7
          if event.key==pygame.K_UP:
             ps-=7  
       if event.type==pygame.KEYUP:
          if event.key==pygame.K_DOWN:
             ps-=7
          if event.key==pygame.K_UP:
             ps+=7  
 
   ballan()

   if player.top<=0 :
      player.top=0
   if player.bottom>=screen_height:
      player.bottom =screen_height


   player.y+=ps

   if opps.top<ball.top:
      opps.y+=os
   if opps.top>ball.top:
      opps.y-=os
   
   if opps.top<=0 :
      opps.top=0
   if opps.bottom>=screen_height:
      opps.bottom =screen_height

   screen.fill(bg)  
   pygame.draw.rect(screen,lg,player)
   pygame.draw.rect(screen,lg,opps)
   pygame.draw.ellipse(screen,lg,ball)   
   pygame.draw.aaline(screen,lg,(screen_width/2,0),(screen_width/2,screen_height))
   pygame.display.flip()
   clock.tick(30)
           
   