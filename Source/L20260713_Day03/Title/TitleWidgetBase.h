// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TitleWidgetBase.generated.h"

class UButton;
class UEditableTextBox;
class UTextBlock;
class UWebApiSubsystem;


/**
 *
 */
UCLASS()
class L20260713_DAY03_API UTitleWidgetBase : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget")
	TObjectPtr<UButton> StartServerButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget", meta = (BindWidget))
	TObjectPtr<UButton> ConnectServerButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget", meta = (BindWidget))
	TObjectPtr<UEditableTextBox> UserID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget", meta = (BindWidget))
	TObjectPtr<UEditableTextBox> Password;

	// 웹서버 주소. 로그인/회원가입/서버등록 HTTP 요청의 대상이다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget", meta = (BindWidget))
	TObjectPtr<UEditableTextBox> ServerIP;

	// 게임 서버 주소. 로그인 응답으로 받은 값이 자동으로 채워진다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget", meta = (BindWidget))
	TObjectPtr<UEditableTextBox> GameServerIP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget", meta = (BindWidget))
	TObjectPtr<UButton> LoginButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget", meta = (BindWidget))
	TObjectPtr<UButton> SignUpButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget", meta = (BindWidget))
	TObjectPtr<UTextBlock> InfoText;

	UFUNCTION()
	void StartServer();

	UFUNCTION()
	void ConnectServer();

	void SaveData();

	UFUNCTION()
	void Login();

	UFUNCTION()
	void SignUp();

	UFUNCTION()
	void ProcessLoginResult(const bool bInSuccess, const FString& InMessage);

	UFUNCTION()
	void ProcessSignUpResult(const bool bInSuccess, const FString& InMessage);

	UFUNCTION()
	void ProcessRegisterServerResult(const bool bInSuccess, const FString& InMessage);

private:

	UWebApiSubsystem* GetWebApi() const;

	bool IsLoggedIn() const;

	bool ValidateInput();

	void SetInfoText(const FString& InMessage);

	void ClearLoginState();

	bool bRequestInFlight = false;

};
